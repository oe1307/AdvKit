import math
import os
from typing import Callable, Iterator

from robustbench.data import load_cifar10, load_cifar100, load_imagenet
from torch import Tensor
from torchvision.datasets.imagenet import parse_devkit_archive, parse_val_archive

from pyadv.utils import config_parser, savedir

config = config_parser()


def batch_process(data: Tensor, label: Tensor, size: int) -> Iterator:
    """
    Batch processing from data and label
    >>> for x, y in batch_process(data, label, size=10):
    >>>     print(x == data[:10])
    """
    n_batch = math.ceil(len(data) / size)
    for b in range(n_batch):
        start = b * size
        end = min((b + 1) * size, len(data))
        x = data[start:end].to(config.device)
        y = label[start:end].to(config.device)
        yield x, y


def get_dataset(transform: Callable, path: str = savedir.path):
    assert "dataset" in config, "please specify the dataset in the config"
    if config.dataset == "cifar10":
        data, label = load_cifar10(config.n_examples, path, transform)
    elif config.dataset == "cifar100":
        data, label = load_cifar100(config.n_examples, path, transform)
    elif config.dataset == "imagenet":
        decompress_imagenet(path)
        data, label = load_imagenet(config.n_examples, path, transform)
    else:
        raise ValueError(f"Unknown dataset {config.dataset}")
    return data, label


def decompress_imagenet(path: str = savedir.path):
    """
    Decompresses the imagenet dataset.
        ILSVRC2012_devkit_t12.tar.gz -> meta.bin
        ILSVRC2012_img_val.tar -> val/class_id/*.JPEG
    """
    if not os.path.exists(f"{path}/ILSVRC2012_devkit_t12.tar.gz"):
        raise FileExistsError("ILSVRC2012_devkit_t12.tar.gz not found")
    elif not os.path.exists(f"{path}/meta.bin"):
        print(f"Decompressing imagenet label: {path}/ILSVRC2012_devkit_t12.tar.gz")
        parse_devkit_archive(path)

    if not os.path.exists(f"{path}/ILSVRC2012_img_val.tar"):
        raise FileExistsError("ILSVRC2012_img_val.tar not found")
    elif not os.path.exists(f"{path}/val"):
        print(f"Decompressing imagenet dataset: {path}/ILSVRC2012_img_val.tar")
        parse_val_archive(path)
