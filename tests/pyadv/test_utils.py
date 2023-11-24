from pyadv import config_parser


def test_load_json():
    config_parser().clear()
    config = config_parser.read("tests/storage/config.json")
    assert list(config.keys()) == [
        "test1_int",
        "test1_float",
        "test1_str",
        "test1_list",
        "test1_dict",
        "test1_bool",
        "test1_none",
        "test1_empty",
        "test1_empty_list",
        "test1_empty_dict",
    ]
    assert config.test1_int == 1
    assert config.test1_float == 1.1
    assert config.test1_str == "test1_1"
    assert config.test1_list == [1.2, 1.3, 1.4]
    assert config.test1_dict == {"test1_2": 1.5, "test1_3": 1.6}
    assert config.test1_bool is True
    assert config.test1_none is None
    assert config.test1_empty == ""
    assert config.test1_empty_list == []
    assert config.test1_empty_dict == {}


def test_load_toml():
    config_parser().clear()
    config = config_parser.read("tests/storage/config.toml")
    assert list(config.keys()) == [
        "test2_int",
        "test2_float",
        "test2_str",
        "test2_list",
        "test2_dict",
        "test2_bool",
        "test2_empty_list",
    ]
    assert config.test2_int == 2
    assert config.test2_float == 2.1
    assert config.test2_str == "test2_1"
    assert config.test2_list == [2.2, 2.3, 2.4]
    assert config.test2_dict == {"test2_2": 2.5, "test2_3": 2.6}
    assert config.test2_bool is True
    assert config.test2_empty_list == []


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
