#ifndef SRC_SELECTOR_CONFIG_HPP_
#define SRC_SELECTOR_CONFIG_HPP_

#include <stdexcept>

#include "../base_attacker.hpp"
#include "whitebox/fgsm.hpp"

Config* get_config(dict args, dict params) {
    dict config = args;
    config.merge(params);

    if (config["attacker"] == "FGSM") {
        return new FGSM_Config(config);
    } else {
        throw std::invalid_argument("Invalid attacker");
    }
}

#endif  // SRC_SELECTOR_CONFIG_HPP_
