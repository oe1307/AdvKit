import torch
from torch import Tensor
from torch.nn import Module

from pyadv.data import batch_process
from pyadv.utils import config_parser, pbar

config = config_parser()


class Attacker:
    @torch.no_grad()
    def attack(self, model: Module, data: Tensor, label: Tensor):
        self.model = model

        # remove misclassified data
        success_classify = self.classify(data, label, "clean")
        target_data, target_label = data[success_classify], label[success_classify]
        self.n_images, self.n_channel, self.height, self.width = target_data.shape
        adex = self._attack(target_data, target_label)

        # check attack success rate
        adex = self.check_adex(adex, target_data)
        is_robust_image = self.classify(adex, target_label, "adversarial")
        attack_success_rate = (1 - is_robust_image.sum() / len(data)) * 100
        print(f"Attack Success Rate: {attack_success_rate:.2f}%")
        adversarial_data = data.clone()
        adversarial_data[success_classify] = adex
        return adversarial_data

    def _attack(self, data: Tensor, label: Tensor):
        raise NotImplementedError()

    def classify(self, data: Tensor, label: Tensor, dset: str):
        # FIXME: targeted, untargeted
        success = torch.tensor([], dtype=torch.bool)
        batch = batch_process(data, label, config.batch_size)
        for x, y in pbar(batch, f"classify {dset} data"):
            prediction = self.model(x).softmax(dim=1)
            success = torch.cat((success, (prediction.argmax(dim=1) == y).cpu()), dim=0)
        return success

    def check_adex(self, adex: Tensor, x: Tensor):
        if config.norm == "Linf":
            upper = (x + config.epsilon).clamp(0, 1)
            lower = (x - config.epsilon).clamp(0, 1)
            adex = adex.clamp(lower, upper)
        elif config.norm == "L2":
            raise NotImplementedError
        return adex
