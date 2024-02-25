#!/usr/bin/env python3

import torch

tmp_input = torch.randn(1, 3, 32, 32)
torch.hub.set_dir("tests/example")
model = torch.hub.load("chenyaofo/pytorch-cifar-models", "cifar10_resnet20")

try:
    model_script = torch.jit.script(model)
except Exception:
    model_script = torch.jit.trace(model, tmp_input)
model_script.save("test_model_jit.pt")
