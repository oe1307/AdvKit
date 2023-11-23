#ifndef SRC_ATTACKER_FGSM_HPP_
#define SRC_ATTACKER_FGSM_HPP_

#include "../base/attacker.hpp"

class FGSM : public Attacker {
   public:
    explicit FGSM(Config config) : Attacker(config) {}

    void _attack() override;
};

#endif  // SRC_ATTACKER_FGSM_HPP_
