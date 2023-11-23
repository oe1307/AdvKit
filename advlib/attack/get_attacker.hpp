#ifndef SRC_SELECTOR_ATTACKER_HPP_
#define SRC_SELECTOR_ATTACKER_HPP_

#include <stdexcept>

#include "../base_attacker.hpp"
#include "attack/whitebox/fgsm.hpp"

Attacker* get_attacker(Config config) {
    if (config.attacker == "FGSM") {
        return new FGSM(config);
    } else {
        throw std::invalid_argument("Invalid attacker: " + config.attacker);
    }
}
#endif  // SRC_SELECTOR_ATTACKER_HPP_
