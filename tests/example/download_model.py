#!/usr/bin/env python3

import math
import os
from collections import OrderedDict

import requests  # type: ignore
import torch
import torch.nn as nn
import torch.nn.functional as F
from torch import Tensor


class BasicBlock(nn.Module):  # type: ignore
    def __init__(
        self, in_planes: int, out_planes: int, stride: int, dropRate: float = 0.0
    ):
        super(BasicBlock, self).__init__()
        self.bn1 = nn.BatchNorm2d(in_planes)
        self.relu1 = nn.ReLU(inplace=True)
        self.conv1 = nn.Conv2d(
            in_planes, out_planes, kernel_size=3, stride=stride, padding=1, bias=False
        )
        self.bn2 = nn.BatchNorm2d(out_planes)
        self.relu2 = nn.ReLU(inplace=True)
        self.conv2 = nn.Conv2d(
            out_planes, out_planes, kernel_size=3, stride=1, padding=1, bias=False
        )
        self.droprate = dropRate
        self.equalInOut = in_planes == out_planes
        self.convShortcut = (
            (not self.equalInOut)
            and nn.Conv2d(
                in_planes,
                out_planes,
                kernel_size=1,
                stride=stride,
                padding=0,
                bias=False,
            )
            or None
        )

    def forward(self, x: Tensor) -> Tensor:
        if not self.equalInOut:
            x = self.relu1(self.bn1(x))
        else:
            out = self.relu1(self.bn1(x))
        out = self.relu2(self.bn2(self.conv1(out if self.equalInOut else x)))
        if self.droprate > 0:
            out = F.dropout(out, p=self.droprate, training=self.training)
        out = self.conv2(out)
        output = x if self.equalInOut else self.convShortcut(x), out  # type: ignore
        return torch.add(output)


class NetworkBlock(nn.Module):  # type: ignore
    def __init__(
        self,
        nb_layers: float,
        in_planes: int,
        out_planes: int,
        block: nn.Module,
        stride: int,
        dropRate: float = 0.0,
    ):
        super(NetworkBlock, self).__init__()
        self.layer = self._make_layer(
            block, in_planes, out_planes, nb_layers, stride, dropRate
        )

    def _make_layer(
        self,
        block: nn.Module,
        in_planes: int,
        out_planes: int,
        nb_layers: float,
        stride: int,
        dropRate: float,
    ) -> nn.Module:
        layers = []
        for i in range(int(nb_layers)):
            layers.append(
                block(
                    i == 0 and in_planes or out_planes,
                    out_planes,
                    i == 0 and stride or 1,
                    dropRate,
                )
            )
        return nn.Sequential(*layers)

    def forward(self, x: Tensor) -> Tensor:
        return self.layer(x)


class WideResNet(nn.Module):  # type: ignore
    def __init__(
        self,
        depth: int = 28,
        num_classes: int = 10,
        widen_factor: int = 10,
        sub_block1: bool = False,
        dropRate: float = 0.0,
        bias_last: bool = True,
    ):
        super(WideResNet, self).__init__()
        nChannels = [16, 16 * widen_factor, 32 * widen_factor, 64 * widen_factor]
        assert (depth - 4) % 6 == 0
        n = (depth - 4) / 6
        block = BasicBlock
        self.conv1 = nn.Conv2d(
            3, nChannels[0], kernel_size=3, stride=1, padding=1, bias=False
        )
        self.block1 = NetworkBlock(n, nChannels[0], nChannels[1], block, 1, dropRate)
        if sub_block1:
            self.sub_block1 = NetworkBlock(
                n, nChannels[0], nChannels[1], block, 1, dropRate
            )
        self.block2 = NetworkBlock(n, nChannels[1], nChannels[2], block, 2, dropRate)
        self.block3 = NetworkBlock(n, nChannels[2], nChannels[3], block, 2, dropRate)
        self.bn1 = nn.BatchNorm2d(nChannels[3])
        self.relu = nn.ReLU(inplace=True)
        self.fc = nn.Linear(nChannels[3], num_classes, bias=bias_last)
        self.nChannels = nChannels[3]

        for m in self.modules():
            if isinstance(m, nn.Conv2d):
                n = m.kernel_size[0] * m.kernel_size[1] * m.out_channels
                m.weight.data.normal_(0, math.sqrt(2.0 / n))
            elif isinstance(m, nn.BatchNorm2d):
                m.weight.data.fill_(1)
                m.bias.data.zero_()
            elif isinstance(m, nn.Linear) and m.bias is not None:
                m.bias.data.zero_()

    def forward(self, x: Tensor) -> Tensor:
        out = self.conv1(x)
        out = self.block1(out)
        out = self.block2(out)
        out = self.block3(out)
        out = self.relu(self.bn1(out))
        out = F.avg_pool2d(out, 8)
        out = out.view(-1, self.nChannels)
        return self.fc(out)


CANNED_USER_AGENT = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.95 Safari/537.36"  # NOQA


def download_gdrive(gdrive_id: str, fname_save: str) -> None:
    url_base = "https://docs.google.com/uc?export=download&confirm=t"
    session = requests.Session()
    session.headers.update({"User-Agent": CANNED_USER_AGENT})
    response = session.get(url_base, params={"id": gdrive_id}, stream=True)
    CHUNK_SIZE = 32768
    with open(fname_save, "wb") as f:
        for chunk in response.iter_content(CHUNK_SIZE):
            if chunk:  # filter out keep-alive new chunks
                f.write(chunk)
    session.close()


def rm_substr_from_state_dict(
    state_dict: OrderedDict[str, Tensor], substr: str
) -> OrderedDict[str, Tensor]:
    new_state_dict = OrderedDict()
    for key in state_dict.keys():
        if substr in key:
            new_key = key[len(substr) :]
            new_state_dict[new_key] = state_dict[key]
        else:
            new_state_dict[key] = state_dict[key]
    return new_state_dict


# Carmon2019Unlabeled
gdrive_id = "15tUx-gkZMYx7BfEOw1GY5OKC-jECIsPQ"
path = "tests/example/test_model.pt"

if not os.path.exists(path):
    print(f"Download started: {path=} ({gdrive_id=})")
    download_gdrive(gdrive_id, path)
model = WideResNet(depth=28, widen_factor=10, sub_block1=True)
checkpoint = torch.load(path, map_location="cpu")
state_dict = rm_substr_from_state_dict(checkpoint["state_dict"], "module.")
state_dict = rm_substr_from_state_dict(state_dict, "model.")
model.load_state_dict(state_dict, strict=True)
model = model.eval()

tmp_input = torch.randn(1, 3, 32, 32)
model_script = torch.jit.trace(model, tmp_input)
model_script.save("test_model_jit.pt")
