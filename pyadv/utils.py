import collections
import itertools
import json
import os
import pprint
import random
from collections.abc import Iterable
from itertools import tee
from logging import DEBUG, StreamHandler, getLogger
from typing import Dict, Union

import yaml  # type: ignore


def fix_seed(seed=0, use_numpy=True, use_torch=True):
    """Set random seed for reproducibility"""
    random.seed(seed)
    os.environ["PYTHONHASHSEED"] = str(seed)
    os.environ["CUBLAS_WORKSPACE_CONFIG"] = ":4096:8"
    if use_numpy:
        import numpy as np

        np.random.seed(seed)
    if use_torch:
        import torch

        torch.manual_seed(seed)
        torch.backends.cudnn.benchmark = False
        torch.backends.cudnn.deterministic = True
        torch.use_deterministic_algorithms(True)  # raise error if non-deterministic


def setup_logger():
    logger = getLogger("pyadv")
    handler = StreamHandler()
    handler.setLevel(DEBUG)
    logger.setLevel(DEBUG)
    logger.addHandler(handler)


logger = setup_logger()


class ConfigParser(dict):
    def __init__(self):
        super().__init__()
        self.__dict__ = self

    def read(self, path: str):
        extention = os.path.splitext(path)[1]
        if extention in (".yaml", ".yml"):
            self.update(yaml.safe_load(open(path, "r")))
        elif extention == ".json":
            self.update(json.load(open(path, "r")))
        elif extention == ".toml":
            import tomllib

            self.update(tomllib.load(open(path, "rb")))
        else:
            raise NotImplementedError(f"Unsupported file type: {extention}")
        return self

    def __str__(self):
        return pprint.pformat(self, width=40)

    def __call__(self, obj: Union[Dict, None] = None):
        if obj is not None:
            self.update(obj)
        return self


config_parser = ConfigParser()


class ProgressBar:
    logger = getLogger("pyadv.pbar")
    handler = StreamHandler()
    handler.terminator = ""
    logger.addHandler(handler)

    def __init__(
        self, total: int, fmsg: str = "", bmsg: str = "", length=10, start: int = 0
    ):
        """
        Args:
            total (int): total number of iterations
            fmsg (str): front message. Defaults to "".
            bmsg (str): back message. Defaults to "".
            start (int): start number. Defaults to 0.
        """
        self.total = total
        self.fmsg = fmsg
        self.bmsg = bmsg
        self.length = length
        self.iter = start
        percent = int((self.iter) / self.total * self.length)
        bar = " [" + ("#" * percent).ljust(self.length, " ") + "] "
        self.logger.info(f"\r{self.fmsg}{bar}{start}/{self.total} {self.bmsg}")

    def step(self, n: int = 1):
        self.iter += n
        percent = int((self.iter) / self.total * self.length)
        bar = " [" + ("#" * percent).ljust(self.length, " ") + "] "
        self.logger.info(f"\r{self.fmsg}{bar}{self.iter}/{self.total} {self.bmsg}")

    def end(self):
        percent = int((self.iter) / self.total * self.length)
        bar = " [" + ("#" * percent).ljust(self.length, " ") + "] "
        self.logger.info(f"{self.fmsg}{bar}{self.iter}/{self.total} {self.bmsg}")


def pbar(iterator: Iterable, fmsg: str = "", bmsg: str = ""):
    def count(iterator):
        counter = itertools.count()
        collections.deque(zip(iterator, counter), maxlen=0)
        return next(counter)

    iterator, counter = tee(iterator)
    total = count(counter)
    bar = ProgressBar(total, fmsg, bmsg)
    for i, item in enumerate(iterator):
        yield item
        bar.step()
    bar.end()


def prange(*args, **kwargs):
    total = len(range(*args, **kwargs))
    bar = ProgressBar(total, *args, **kwargs)
    for i in range(*args, **kwargs):
        yield i
        bar.step()
    bar.end()
