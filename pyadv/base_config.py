from utils import ConfigParser


class Config(ConfigParser):
    attacker: str
    norm: str
    epsilon: float
    dataset: str
    model: str
    n_examples: int
    batch_size: int
    device: str
