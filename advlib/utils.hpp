#ifndef ADVLIB_UTILS_HPP_
#define ADVLIB_UTILS_HPP_

#include <stdlib.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "./functions.hpp"

namespace advlib {

inline void fix_seed(int seed = 0) {
    /** Set random seed for reproducibility **/
    setenv("PYTHONHASHSEED", std::to_string(seed).c_str(), 1);
    setenv("CUBLAS_WORKSPACE_CONFIG", ":4096:8", 1);
}

extern functions::Logger logger;

class BaseConfig {
   public:
    virtual void update(functions::dict setting) = 0;
    void read(std::string path) {
        functions::dict setting;
        std::string extention;

        extention = std::filesystem::path(path).extension();
        if (extention == ".yaml" || extention == ".yml") {
            setting = functions::load_yaml(path);
        } else if (extention == ".json") {
            setting = functions::load_json(path);
        } else if (extention == ".toml") {
            setting = functions::load_toml(path);
        } else {
            throw std::runtime_error("Unsupported file format: " + extention);
        }
        this->update(setting);
    }
};

class ProgressBar {
   private:
    functions::Logger logger;
    int total, length, iter, percent;
    std::string fmsg, bmsg, bar;

   public:
    explicit ProgressBar(int total, std::string fmsg = "",
                         std::string bmsg = "", int length = 10,
                         int start = 10) {
        this->total = total;
        this->fmsg = fmsg;
        this->bmsg = bmsg;
        this->length = length;
        this->iter = start;
        this->percent = this->iter / this->total * this->length;
        this->bar = "[" + std::string(this->percent, '#') +
                    std::string(this->length - this->percent, ' ') + "] ";
    }
    void step(int n = 1);
    void end();
};

}  // namespace advlib

#endif  // ADVLIB_UTILS_HPP_
