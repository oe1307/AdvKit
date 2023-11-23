#ifndef ADVLIB_ATTACK_GET_CONFIG_HPP_
#define ADVLIB_ATTACK_GET_CONFIG_HPP_

#include <stdexcept>

#include "../base_attacker.hpp"
#include "whitebox/fgsm.hpp"

inline Config* get_config(dict config) {
    if (config["attacker"] == "Fgsm") {
        return new FgsmParameter(config);
    } else {
        throw std::invalid_argument("Invalid attacker");
    }
}

#endif  // ADVLIB_ATTACK_GET_CONFIG_HPP_
