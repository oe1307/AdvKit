from torch import Tensor

from pyadv.utils import config_parser

config = config_parser()


def get_initial_point():
    if config.initial_point == "original":
        initial_point = OriginalPoint()
    else:
        raise NotImplementedError(config.initial_point)
    return initial_point


class OriginalPoint:
    def __call__(self, x: Tensor):
        return x
