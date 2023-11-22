from pyadv.attack.blackbox import *  # noqa
from pyadv.attack.blackbox import blackbox_attacker
from pyadv.attack.whitebox import *  # noqa
from pyadv.attack.whitebox import whitebox_attacker
from pyadv.utils import config_parser

config = config_parser()


def get_attacker():
    if config.attacker in whitebox_attacker.keys():
        attacker = whitebox_attacker[config.attacker]()
    elif config.attacker in blackbox_attacker.keys():
        attacker = blackbox_attacker[config.attacker]()
    else:
        raise NotImplementedError(config.attacker)
    return attacker
