#ifndef SRC_BASE_ATTACKER_HPP_
#define SRC_BASE_ATTACKER_HPP_

#include "./model.hpp"

namespace advlib {

class Attacker {
   public:
    void attack(Model model, torch::Tensor data, torch::Tensor label);

   private:
    void _attack(torch::Tensor data, torch::Tensor label);
};

}  // namespace advlib

#endif  // SRC_BASE_ATTACKER_HPP_
