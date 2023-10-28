import torch
from torch import Tensor

from pyadv.attack.whitebox.core import get_initial_point, get_projection
from pyadv.base import Attacker
from pyadv.criterion import get_criterion
from pyadv.data import batch_process
from pyadv.utils import config_parser, pbar

config = config_parser()


class FGSM(Attacker):
    def __init__(self):
        self.criterion = get_criterion()
        self.initial_point = get_initial_point()
        print("Hyperparameters: \n")

    def _attack(self, data: Tensor, label: Tensor):
        adex = list()
        batch = batch_process(data, label, config.batch_size)
        for x, y in pbar(batch, "FGSM"):
            projection = get_projection(x)
            x_adv = self.initial_point(x)

            # calculate gradient of initial point
            with torch.enable_grad():
                x_adv = x_adv.clone().requires_grad_()
                prediction = self.model(x_adv).softmax(dim=1)
                loss = self.criterion(prediction, y)
                grad = torch.autograd.grad(loss.sum(), [x_adv])[0].detach()
            x_best = x_adv.clone()
            best_loss = loss.clone()

            # update
            with torch.enable_grad():
                x_adv = projection(x_adv.detach() + config.epsilon * grad.sign())
                prediction = self.model(x_adv).softmax(dim=1)
                loss = self.criterion(prediction, y)
            update = loss >= best_loss
            x_best = x_adv[update].clone()
            adex.append(x_best.cpu())

        adex = torch.cat(adex, dim=0)
        return adex
