from pyadv import config_parser


def test_from_dict():
    config = config_parser({"test1": "ok"})
    print(config)
    assert config["test1"] == "ok"
    assert list(config.keys()) == ["test1"]


def test_read_toml():
    config = config_parser.read("tests/config.toml")
    print(config)
    assert config["test1"] == "ok"
    assert config["test2"] == "ok"
    assert list(config.keys()) == ["test1", "test2"]


def test_read_yaml():
    config = config_parser.read("tests/config.yaml")
    print(config)
    assert config["test1"] == "ok"
    assert config["test2"] == "ok"
    assert config["test3"] == "ok"
    assert list(config.keys()) == ["test1", "test2", "test3"]


def test_clear_config():
    config = config_parser()
    config.clear()
    assert config == {}
