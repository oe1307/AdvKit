#ifndef ADVLIB_ATTACK_WHITEBOX_FGSM_HPP_
#define ADVLIB_ATTACK_WHITEBOX_FGSM_HPP_

#include <string>

#include "../../base_attacker.hpp"
#include "../../base_config.hpp"

namespace advlib {

class FgsmConfig : public Config {
   public:
    std::string criterion;
    void update(functions::dict setting) { Config::update(setting); }
};

class Fgsm : public Attacker {
   private:
    void _attack() override;
};

}  // namespace advlib

#endif  // ADVLIB_ATTACK_WHITEBOX_FGSM_HPP_
