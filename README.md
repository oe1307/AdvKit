# AdvKit

<div align="center"><img alt="AdvKit" width=70% src="https://github.com/oe1307/AdvKit/blob/images/advkit.png?raw=true"></div>
<div align="center"><h3>cpp/python implementation for adversarial attack</h3></div>

## Install

### python

```
pip3 install git+https://github.com/oe1307/AdvKit.git@main
```

### c++

```
git clone -b main git+https://github.com/oe1307/AdvKit.git && cd AdvKit && make install
```

## Usage

### Run with python imprementation

```python
from pyadv import get_attacker, get_model, get_dataset, config_parser

config = config_parser.read()
attacker = get_attacker()
model, transform = get_model()
data, label = get_dataset()
attacker.attack(model, data, label)

```

### Run with c++ imprementation

```c++
#include advlib


```

## Use from source code

### python

```
pip install -e .
python3 -m pyadv -c <config.toml> -g <GPU_id/mpu/cpu> -t <n_thread> -p <params to override>
```

### c++

```
./bin/attack -c <config.toml> -g <GPU_id/mpu/cpu> -t <n_thread> -p <params to override>
```

## None

attackers information is avilable in []()
