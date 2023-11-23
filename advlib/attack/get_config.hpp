#ifndef SRC_SELECTOR_CONFIG_HPP_
#define SRC_SELECTOR_CONFIG_HPP_

#include "../base/config.hpp"

Config* get_config(dict args, dict params);

#endif  // SRC_SELECTOR_CONFIG_HPP_


#include "./config.hpp"

#include <stdexcept>

#include "../config/fgsm.hpp"

Config* get_config(dict args, dict params) {
    dict config = args;
    config.merge(params);

    if (config["attacker"] == "FGSM") {
        return new FGSM_Config(config);
    } else {
        throw std::invalid_argument("Invalid attacker");
    }
}
