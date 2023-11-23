import torch

from pyadv import config_parser, get_attacker, get_dataset, get_model, logger


def test_fgsm():
    setting = {
        "attacker": "FGSM",
        "norm": "Linf",
        "epsilon": 0.015625,
        "dataset": "cifar10",
        "n_examples": 10,
        "model": "Carmon2019Unlabeled",
        "batch_size": 10,
        # --- parameter ---
        "criterion": "cw",
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
    model = get_model()
    data, label = get_dataset()

    attacker.attack(model, data, label)
