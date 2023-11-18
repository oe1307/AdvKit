import torch

from pyadv import config_parser, get_attacker, get_dataset, get_model


def test_fgsm():
    setting = {
        "attacker": "FGSM",
        "norm": "Linf",
        "epsilon": 0.015625,
        "criterion": "cw",
        "initial_point": "original",
        "dataset": "cifar10",
        "n_examples": 100,
        "model": "Carmon2019Unlabeled",
        "batch_size": 100,
    }
    config = config_parser(setting)
    if torch.backends.cudnn.is_available():
        config.device = 0
    elif torch.backends.mps.is_available():
        config.device = "mps"
    else:
        raise RuntimeError("No GPU found")

    attacker = get_attacker()
    model, transform = get_model()
    data, label = get_dataset(transform)
    attacker.attack(model, data, label)
    config.clear()
