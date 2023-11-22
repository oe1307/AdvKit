import torch
from torch import Tensor

from pyadv.attack.whitebox.core import get_projection
from pyadv.base_attacker import Attacker
from pyadv.criterion import get_criterion
from pyadv.data import batch_process
from pyadv.utils import config_parser, logger, prange

config = config_parser()


class IterativeFGSM(Attacker):
    def __init__(self):
        self.criterion = get_criterion()
        self.check_hyperparameters()

    def _attack(self, data: Tensor, label: Tensor):
        adversarial_example = list()
        batch = batch_process(data, label, config.batch_size)
        for b, (x, y) in enumerate(batch):
            projection = get_projection(x)
            x_adv = x.clone()

            # calculate gradient of initial point
            with torch.enable_grad():
                x_adv = x_adv.clone().requires_grad_()
                prediction = self.model(x_adv).softmax(dim=1)
                loss = self.criterion(prediction, y)
                grad = torch.autograd.grad(loss.sum(), [x_adv])[0].detach()
            x_best = x_adv.clone()
            best_loss = loss.clone()

            # update
            for iter in prange(config.iteration, f"batch:{b}"):
                with torch.enable_grad():
                    x_adv = projection(x_adv.detach() + config.epsilon * grad.sign())
                    prediction = self.model(x_adv).softmax(dim=1)
                    loss = self.criterion(prediction, y)
                update = loss >= best_loss
                x_best = x_adv[update].clone()
            adversarial_example.append(x_best.cpu())

        adex = torch.cat(adversarial_example, dim=0)
        return adex

    def check_hyperparameters(self):
        logger.debug(
            "Hyperparameters: \n"
            + f" norm: {config.norm}\n"
            + f" epsilon: {config.epsilon}\n"
            + f" criterion: {config.criterion}\n"
        )
