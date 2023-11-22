from pyadv.utils import config_parser

config = config_parser()


def get_initial_point(method: str):
    if method == "":
        initial_point = None
    else:
        raise NotImplementedError(method)
    return initial_point
