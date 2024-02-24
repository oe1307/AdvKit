#ifndef SRC_BASE_CONFIG_HPP_
#define SRC_BASE_CONFIG_HPP_

#include <string>

#include "./utils.hpp"

namespace advlib {

class Config {
   public:
    dict setting;
    std::string attacker;
    std::string norm;
    float epsilon;
    std::string dataset;
    std::string model;
    int n_examples;
    int batch_size;
    std::string device;

    void check_keys(dict setting);
    std::string value();

    explicit Config(dict setting) {
        check_keys(setting);
        this->setting = setting;
        this->attacker = setting["attacker"];
        this->norm = setting["norm"];
        this->epsilon = stof(setting["epsilon"]);
        this->dataset = setting["dataset"];
        this->n_examples = stoi(setting["n_examples"]);
        this->model = setting["model"];
        this->batch_size = stoi(setting["batch_size"]);
        this->device = setting["device"];
    }
};

}  // namespace advlib

#endif  // SRC_BASE_CONFIG_HPP_
