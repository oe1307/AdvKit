from pyadv.attack.whitebox import *  # noqa
from pyadv.attack.whitebox import whitebox_attacker
from pyadv.utils import config_parser

config = config_parser()


def get_attacker():
    if config.attacker in whitebox_attacker.keys():
        attacker = whitebox_attacker[config.attacker]()
    else:
        raise NotImplementedError(config.attacker)
    return attacker
