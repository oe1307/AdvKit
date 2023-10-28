#ifndef SRC_BASE_CONFIG_HPP_
#define SRC_BASE_CONFIG_HPP_

#include <map>
#include <string>

#include "../utils/functions.hpp"

using dict = std::map<std::string, std::string>;

class Config {
   public:
    std::string basedir;
    std::string savedir;
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
        this->basedir = args["basedir"];
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

#endif  // SRC_BASE_CONFIG_HPP_
