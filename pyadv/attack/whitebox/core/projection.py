from torch import Tensor

from pyadv.utils import config_parser

config = config_parser()


def get_projection(x: Tensor):
    if config.norm == "Linf":
        projection = LinfProjection(x)
    else:
        raise NotImplementedError()
    return projection


class LinfProjection:
    def __init__(self, x: Tensor):
        self.upper = (x + config.epsilon).clamp(0, 1)
        self.lower = (x - config.epsilon).clamp(0, 1)

    def __call__(self, x: Tensor):
        return x.clamp(self.lower, self.upper)
