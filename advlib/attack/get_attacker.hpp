#ifndef ADVLIB_ATTACK_GET_ATTACKER_HPP_
#define ADVLIB_ATTACK_GET_ATTACKER_HPP_

#include <stdexcept>

#include "../base_attacker.hpp"
#include "../utils.hpp"
#include "whitebox/fgsm.hpp"

namespace advlib {

inline Attacker* get_attacker() {
    // Parameter config = config_parser().get();
    // if (config.attacker == "Fgsm") {
    //     return new Fgsm();
    // } else {
    //     throw std::invalid_argument("Invalid attacker: " + config.attacker);
    // }
    return new Fgsm();
}

}  // namespace advlib

#endif  // ADVLIB_ATTACK_GET_ATTACKER_HPP_
