#ifndef ADVLIB_BASE_CONFIG_HPP_
#define ADVLIB_BASE_CONFIG_HPP_

#include <string>

#include "./utils.hpp"

namespace advlib {

class Config : public ConfigParser {
   public:
    std::string attacker;
    std::string norm;
    float epsilon;
    std::string dataset;
    std::string model;
    int n_examples;
    int batch_size;
    std::string device;

    void update(functions::dict setting) override {
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

}  // namespace advlib

#endif  // ADVLIB_BASE_ATTACKER_HPP_
