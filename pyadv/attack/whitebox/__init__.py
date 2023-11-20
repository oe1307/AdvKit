from pyadv.attack.whitebox.fgsm import FGSM
from pyadv.attack.whitebox.iterative_fgsm import Iterative_FGSM

whitebox_attacker = {
    "FGSM": FGSM,
    "Iterative_FGSM": Iterative_FGSM
}
