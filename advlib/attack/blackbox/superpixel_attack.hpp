#ifndef ADVLIB_ATTACK_BLACKBOX_FGSM_HPP_
#define ADVLIB_ATTACK_BLACKBOX_FGSM_HPP_

#include "../../base_attacker.hpp"
#include "../../base_config.hpp"

namespace advlib {

class SuperpixelAttackConfig : public Config {};

class SuperpixelAttack : public Attacker {
    inline void _attack() {}
};

}  // namespace advlib

#endif  // ADVLIB_ATTACK_BLACKBOX_FGSM_HPP_
