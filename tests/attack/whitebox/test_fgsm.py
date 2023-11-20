import torch

from pyadv import config_parser, get_attacker, get_dataset, get_model, logger


def test_fgsm():
    setting = {
        "attacker": "FGSM",
        "norm": "Linf",
        "epsilon": 0.015625,
        "criterion": "cw",
        "dataset": "cifar10",
        "n_examples": 100,
        "model": "Carmon2019Unlabeled",
        "batch_size": 100,
    }
    config_parser().clear()
    config = config_parser(setting)
    if torch.backends.cudnn.is_available():
        config.device = "cuda"
    elif torch.backends.mps.is_available():
        config.device = "mps"
    else:
        raise RuntimeError("No GPU found")

    logger.setLevel("DEBUG")
    attacker = get_attacker()
    model, transform = get_model()
    data, label = get_dataset(transform)

    attacker.attack(model, data, label)
