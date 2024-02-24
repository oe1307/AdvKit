#!/usr/bin/env python3

import os
import sys

import torch
from robustbench import load_model
from robustbench.model_zoo.enums import BenchmarkDataset, ThreatModel

model_name = "Carmon2019Unlabeled"
dataset = BenchmarkDataset.cifar_10
norm = ThreatModel.Linf
savedir = os.path.dirname(sys.argv[0]) + "/../storage"

if dataset in (BenchmarkDataset.cifar_10, BenchmarkDataset.cifar_100):
    tmp_input = torch.randn(1, 3, 32, 32)
else:
    raise NotImplementedError(dataset)

model = load_model(model_name, savedir, dataset, norm=norm).eval()

try:
    model_script = torch.jit.script(model)
except Exception:
    model_script = torch.jit.trace(model, tmp_input)
model_script.save(f"{savedir}/{dataset.value}/{norm.value}/{model_name}_jit.pt")
