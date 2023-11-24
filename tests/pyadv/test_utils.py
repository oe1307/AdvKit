from pyadv import config_parser


def test_load_json():
    config_parser().clear()
    config_parser.read("tests/storage/config.json")


def test_load_toml():
    config_parser().clear()
    config_parser.read("tests/storage/config.toml")


def test_load_yaml():
    config_parser().clear()
    config = config_parser.read("tests/storage/config.yaml")
    assert list(config.keys()) == [
        "test3_int",
        "test3_float",
        "test3_str",
        "test3_list",
        "test3_dict",
        "test3_bool",
        "test3_none",
        "test3_empty_list",
    ]
    assert config.test3_int == 3
    assert config.test3_float == 3.1
    assert config.test3_str == "test3_1"
    assert config.test3_list == [3.2, 3.3, 3.4]
    assert config.test3_dict == {"test3_2": 3.5, "test3_3": 3.6}
    assert config.test3_bool is True
    assert config.test3_none is None
    assert config.test3_empty_list == []
