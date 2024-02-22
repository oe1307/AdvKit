#include <advlib.hpp>
#include <iostream>

int main() {
    try {
        advlib::dict setting = {{"attacker", "Fgsm"},
                                {"norm", "Linf"},
                                {"epsilon", "0.01568627450980392"},
                                {"model", "Carmon2019Unlabeled"},
                                {"dataset", "cifar10"},
                                {"n_examples", "100"},
                                {"batch_size", "100"},
                                {"device", "0"}};
        auto config = advlib::Config(setting);
        std::cout << config.value() << std::endl;
        return 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
