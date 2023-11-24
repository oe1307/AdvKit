from pyadv.attack.blackbox import SuperpixelAttack
from pyadv.attack.whitebox import Fgsm, IterativeFgsm
from pyadv.base_config import Config

attack_methods = {
    # --- whitebox attack ---
    "Fgsm": Fgsm,
    "IterativeFgsm": IterativeFgsm,
    # --- blackbox attack ---
    "SuperpixelAttack": SuperpixelAttack,
}


def get_attacker(config: Config):
    return attack_methods[config.attacker](config)
