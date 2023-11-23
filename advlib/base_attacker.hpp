#ifndef ADVLIB_BASE_ATTACKER_HPP_
#define ADVLIB_BASE_ATTACKER_HPP_

#include <map>
#include <string>

using dict = std::map<std::string, std::string>;

class Config {
   public:
    int device;
    int thread;
    int seed;
    std::string attacker;
    std::string dataset;
    std::string model;
    int batch_size;
    int n_examples;
    int iteration;
    std::string norm;
    float epsilon;

    explicit Config(dict args) {
        this->device = stoi(args["device"]);
        this->thread = stoi(args["thread"]);
        this->seed = stoi(args["seed"]);
        this->attacker = args["attacker"];
        this->dataset = args["dataset"];
        this->n_examples = stoi(args["n_examples"]);
        this->iteration = stoi(args["iteration"]);
        this->norm = args["norm"];
        this->epsilon = stof(args["epsilon"]);
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
