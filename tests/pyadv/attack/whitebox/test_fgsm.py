import torch

from pyadv import Config, get_attacker, get_dataset, get_model, logger


def test_fgsm():
    setting = {
        "attacker": "Fgsm",
        "norm": "Linf",
        "epsilon": 0.015625,
        "dataset": "cifar10",
        "n_examples": 10,
        "model": "Carmon2019Unlabeled",
        "batch_size": 10,
        # --- parameter ---
        "criterion": "cw",
    }
    config = Config(setting)
    if torch.backends.cudnn.is_available():
        config.device = "cuda"
    elif torch.backends.mps.is_available():
        config.device = "mps"
    else:
        raise RuntimeError("No GPU found")

    logger.setLevel("DEBUG")
    attacker = get_attacker(config)
    model = get_model(config)
    data, label = get_dataset(config)

    attacker.attack(model, data, label)
