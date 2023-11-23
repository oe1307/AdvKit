#ifndef ADVLIB_ATTACK_WHITEBOX_FGSM_HPP_
#define ADVLIB_ATTACK_WHITEBOX_FGSM_HPP_

#include "../../base_attacker.hpp"

class FgsmParameter : public Config {
   public:
    explicit FgsmParameter(dict config) : Config(config) {}
};

class Fgsm : public Attacker {
   public:
    explicit Fgsm(Config config) : Attacker(config) {}
    void _attack() override;
};

#endif  // ADVLIB_ATTACK_WHITEBOX_FGSM_HPP_
