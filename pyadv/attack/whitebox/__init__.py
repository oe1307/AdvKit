from pyadv.attack.whitebox.fgsm import FastGradientSignMethod
from pyadv.attack.whitebox.iterative_fgsm import IterativeFGSM

whitebox_attacker = {
    "FGSM": FastGradientSignMethod,
    "Iterative_FGSM": IterativeFGSM,
}
