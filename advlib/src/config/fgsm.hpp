#ifndef SRC_CONFIG_FGSM_HPP_
#define SRC_CONFIG_FGSM_HPP_

#include "../base/config.hpp"

class FGSM_Config : public Config {
   public:
    explicit FGSM_Config(dict config) : Config(config) {}
};

#endif  // SRC_CONFIG_FGSM_HPP_
