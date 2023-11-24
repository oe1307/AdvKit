#ifndef ADVLIB_ATTACK_WHITEBOX_FGSM_HPP_
#define ADVLIB_ATTACK_WHITEBOX_FGSM_HPP_

#include "../../base_attacker.hpp"

namespace advlib {

class FgsmConfig : public Config {
   private:
    void update(functions::dict setting) { Config::update(setting); }
};

class Fgsm : public Attacker {
   private:
    void _attack() override;
};

}  // namespace advlib

#endif  // ADVLIB_ATTACK_WHITEBOX_FGSM_HPP_
