#ifndef ADVLIB_ATTACK_GET_ATTACKER_HPP_
#define ADVLIB_ATTACK_GET_ATTACKER_HPP_

#include <stdexcept>

#include "../base_attacker.hpp"
#include "whitebox/fgsm.hpp"

inline Attacker* get_attacker(Config config) {
    if (config.attacker == "Fgsm") {
        return new Fgsm(config);
    } else {
        throw std::invalid_argument("Invalid attacker: " + config.attacker);
    }
}
#endif  // ADVLIB_ATTACK_GET_ATTACKER_HPP_
