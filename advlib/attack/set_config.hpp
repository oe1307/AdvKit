#ifndef ADVLIB_ATTACK_SET_CONFIG_HPP_
#define ADVLIB_ATTACK_SET_CONFIG_HPP_

#include <map>
#include <stdexcept>
#include <string>

#include "../base_config.hpp"
#include "../utils.hpp"
#include "whitebox/fgsm.hpp"

namespace advlib {

inline std::map<std::string, Config> config_dict = {
    {"Fgsm", FgsmConfig()},
    // {"IterativeFgsm", IterativeFgsm()},
};

inline Config* set_config{};
}  // namespace advlib

#endif  // ADVLIB_ATTACK_SET_CONFIG_HPP_
