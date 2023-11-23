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

    explicit Config(dict args) {
        this->attacker = args["attacker"];
        this->norm = args["norm"];
        this->epsilon = stof(args["epsilon"]);
        this->dataset = args["dataset"];
        this->model = args["model"];
        this->n_examples = stoi(args["n_examples"]);
        this->batch_size = stoi(args["batch_size"]);
        this->device = stoi(args["device"]);
    }

    // TODO: 出力演算子
};

class Attacker {
   public:
    void attack();

   private:
    Config config;
    virtual void _attack() = 0;
};

#endif  // ADVLIB_BASE_ATTACKER_HPP_
