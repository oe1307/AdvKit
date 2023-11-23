#ifndef ADVLIB_ATTACK_WHITEBOX_FGSM_HPP_
#define ADVLIB_ATTACK_WHITEBOX_FGSM_HPP_

#include "../../base_attacker.hpp"

class FGSM_Config : public Config {
   public:
    explicit FGSM_Config(dict config) : Config(config) {}
};

class FGSM : public Attacker {
   public:
    explicit FGSM(Config config) : Attacker(config) {}

    void _attack() override;
};

#endif  // ADVLIB_ATTACK_WHITEBOX_FGSM_HPP_
