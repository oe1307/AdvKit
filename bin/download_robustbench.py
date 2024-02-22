#!/usr/bin/env python3

import os
import sys

from robustbench import load_model
from robustbench.model_zoo.enums import BenchmarkDataset, ThreatModel

model = "Carmon2019Unlabeled"
dataset = BenchmarkDataset.cifar_10
norm = ThreatModel.Linf
savedir = os.path.dirname(sys.argv[0]) + "/../storage"

model = load_model(model, savedir, dataset, norm=norm)
