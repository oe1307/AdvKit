#ifndef SRC_BASE_ATTACKER_HPP_
#define SRC_BASE_ATTACKER_HPP_

#include "./config.hpp"

class Attacker {
   public:
    explicit Attacker(Config config) : config(config) {}
    void attack();

   private:
    Config config;
    virtual void _attack() = 0;
};

#endif  // SRC_BASE_ATTACKER_HPP_
