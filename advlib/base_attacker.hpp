#ifndef ADVLIB_BASE_ATTACKER_HPP_
#define ADVLIB_BASE_ATTACKER_HPP_

#include <map>
#include <string>

#include "./utils.hpp"

namespace advlib {

class Attacker {
   public:
    void attack();

   private:
    virtual void _attack() = 0;
};

}  // namespace advlib

#endif  // ADVLIB_BASE_ATTACKER_HPP_
