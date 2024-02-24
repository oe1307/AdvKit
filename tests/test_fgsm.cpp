#include <advlib.hpp>
#include <iostream>

int main() {
    try {
        auto setting = advlib::load_yaml("tests/example/config.yaml");
        auto config = advlib::Config(setting);
        std::cout << config.value() << std::endl;
        auto model = advlib::get_model(config);
        auto [data, label] = advlib::get_dataset(config);
        return 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
