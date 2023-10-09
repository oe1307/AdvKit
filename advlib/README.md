# Adversarial Attack in c++

## Setup

```bash:AdEx_cpp/
cmake -S . -B .build && cmake --build .build
```

## Usage

```bash:AdEx_cpp/src
./run.exe -p <params path> -g <gpu_id> -t <num threads> -u <params to update>
```

for example:

```bash:AdEx_cpp/src
./run.exe -p ../params/fgsm.yaml -g 0 -t 10 -u n_examples=100
```
