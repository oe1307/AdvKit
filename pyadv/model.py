import os
import warnings

import torch
from robustbench import load_model
from robustbench.data import BenchmarkDataset, ThreatModel, all_models
from torchvision.models import list_models

from pyadv.utils import config_parser

config = config_parser()


def get_model_dict() -> dict:
    model_dict = {"pytorch": list_models(), "robustbench": None}
    if config.dataset in (d.value for d in BenchmarkDataset):
        models = all_models[BenchmarkDataset(config.dataset)][ThreatModel(config.norm)]
        models = list(models.keys())
        model_dict.update({"robustbench": models})
    return model_dict


def get_model(path=os.path.expanduser("~/.cache")):
    torch.hub.set_dir(path)
    models = get_model_dict()

    if config.model in models["pytorch"] and config.dataset == "imagenet":
        raise NotImplementedError
    elif config.model in models["robustbench"]:
        with warnings.catch_warnings():
            warnings.simplefilter("ignore")
            model = load_model(
                config.model,
                path,
                BenchmarkDataset(config.dataset),
                norm=ThreatModel(config.norm),
            )
    else:
        raise ValueError(f"model {config.model} not found")

    model = model.eval().to(config.device)
    return model
