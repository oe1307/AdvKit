# AdvKit

<div align="center"><img alt="AdvKit" width=70% src="https://github.com/oe1307/AdvKit/blob/images/advkit.png?raw=true"></div>
<div align="center"><h3>C++ / Python implementation for Adversarial Attack</h3></div>

<div align="center">
<img src="https://img.shields.io/github/license/oe1307/AdvKit?logo=open-source-initiative&logoColor=green">
<img src="https://img.shields.io/badge/python-3.11-blue.svg">
<img src="https://img.shields.io/github/last-commit/oe1307/AdvKit?logo=git&logoColor=white">
<img src="https://img.shields.io/github/issues/oe1307/AdvKit?logo=github&logoColor=white">
<img src="https://img.shields.io/github/issues-pr/oe1307/AdvKit?logo=github&logoColor=white">
<img src="https://img.shields.io/github/languages/code-size/oe1307/AdvKit?logo=github&logoColor=white">
</div>

## Install

#### Python

```
pip3 install git+https://github.com/oe1307/AdvKit.git
```

#### C++

```
git clone https://github.com/oe1307/AdvKit.git && cd AdvKit && make install
```

## Usage

#### Run with Python imprementation

```python
from pyadv import config_parser, get_attacker, get_dataset, get_model, logger

config = config_parser.read("fgsm.yaml") # support for yaml, json, toml
# or
setting = {
    "attacker": "FGSM",
    "norm": "Linf",
    "epsilon": 0.015625,
    "criterion": "cw",
    "dataset": "cifar10",
    "n_examples": 100,
    "model": "Carmon2019Unlabeled",
    "batch_size": 100,
    "device": 0,
}
config = config_parser(setting)

logger.setLevel("INFO")
attacker = get_attacker()
model, transform = get_model()
data, label = get_dataset(transform)

attacker.attack(model, data, label)

```

#### Run with C++ imprementation

```c++
#include advlib

auto config = advlib::config_parser.read("fgsm.yaml");
auto attacker = advlib::get_attacker();
auto model = advlib::get_model();
auto data = advlib::get_dataset(transform);

attacker.attack(model, data, label);
```

## Note

attackers information is avilable in []()
