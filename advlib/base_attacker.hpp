#ifndef ADVLIB_BASE_ATTACKER_HPP_
#define ADVLIB_BASE_ATTACKER_HPP_

#include <map>
#include <string>

using dict = std::map<std::string, std::string>;

class Config {
   public:
    std::string attacker;
    std::string norm;
    float epsilon;
    std::string dataset;
    std::string model;
    int n_examples;
    int batch_size;
    int device;

    explicit Config(dict setting) {
        this->attacker = setting["attacker"];
        this->norm = setting["norm"];
        this->epsilon = stof(setting["epsilon"]);
        this->dataset = setting["dataset"];
        this->model = setting["model"];
        this->n_examples = stoi(setting["n_examples"]);
        this->batch_size = stoi(setting["batch_size"]);
        this->device = stoi(setting["device"]);
    }

    // TODO: 出力演算子
};

class Attacker {
   public:
    explicit Attacker(Config config) : config(config) {}
    void attack();

   private:
    Config config;
    virtual void _attack() = 0;
};

#endif  // ADVLIB_BASE_ATTACKER_HPP_
