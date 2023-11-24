#ifndef ADVLIB_BASE_ATTACKER_HPP_
#define ADVLIB_BASE_ATTACKER_HPP_

#include <map>
#include <string>

#include "./utils.hpp"

namespace advlib {

class Parameter : public Config {
   public:
    std::string attacker;
    std::string norm;
    float epsilon;
    std::string dataset;
    std::string model;
    int n_examples;
    int batch_size;
    int device;

   private:
    void update(dict setting) override {
        this->attacker = setting["attacker"];
        this->norm = setting["norm"];
        this->epsilon = stof(setting["epsilon"]);
        this->dataset = setting["dataset"];
        this->n_examples = stoi(setting["n_examples"]);
        this->model = setting["model"];
        this->batch_size = stoi(setting["batch_size"]);
        this->device = stoi(setting["device"]);
    }
};

class Attacker {
   public:
    void attack();

   private:
    virtual void _attack() = 0;
};

}  // namespace advlib

#endif  // ADVLIB_BASE_ATTACKER_HPP_
