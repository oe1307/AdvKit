from pyadv.attack.blackbox import SuperpixelAttack
from pyadv.attack.whitebox import Fgsm, IterativeFgsm
from pyadv.utils import config_parser

config = config_parser()

attacker_dict = {
    "blackbox": {
        "SuperpixelAttack": SuperpixelAttack,
    },
    "whitebox": {
        "Fgsm": Fgsm,
        "IterativeFgsm": IterativeFgsm,
    },
}


def get_attacker():
    if config.attacker in attacker_dict["whitebox"]:
        attacker = attacker_dict["whitebox"][config.attacker]()
    elif config.attacker in attacker_dict["blackbox"]:
        attacker = attacker_dict["blackbox"][config.attacker]()
    else:
        raise NotImplementedError(config.attacker)
    return attacker
