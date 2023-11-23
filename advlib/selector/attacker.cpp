#include "./attacker.hpp"

#include <stdexcept>

#include "../attacker/fgsm.hpp"

Attacker* get_attacker(Config config) {
    if (config.attacker == "FGSM") {
        return new FGSM(config);
    } else {
        throw std::invalid_argument("Invalid attacker: " + config.attacker);
    }
}
