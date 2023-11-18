from torch import Tensor

from pyadv.utils import config_parser

config = config_parser()


def get_initial_point(method: str):
    if method == "original":
        initial_point = OriginalPoint()
    else:
        raise NotImplementedError(method)
    return initial_point


class OriginalPoint:
    def __call__(self, x: Tensor):
        return x
