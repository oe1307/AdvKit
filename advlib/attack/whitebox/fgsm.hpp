#ifndef ADVLIB_ATTACK_WHITEBOX_FGSM_HPP_
#define ADVLIB_ATTACK_WHITEBOX_FGSM_HPP_

#include "../../base_attacker.hpp"

namespace advlib {

class FgsmParameter : public Parameter{
   public:
    explicit FgsmParameter(dict setting) : Parameter(setting) {}
};

class Fgsm : public Attacker {
   public:
    explicit Fgsm(Config config) : Attacker(config) {}
    void _attack() override;
};

}  // namespace advlib

#endif  // ADVLIB_ATTACK_WHITEBOX_FGSM_HPP_
