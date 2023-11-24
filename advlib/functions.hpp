#ifndef ADVLIB_FUNCTIONS_HPP_
#define ADVLIB_FUNCTIONS_HPP_

#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

namespace functions {

using dict = std::map<std::string, std::string>;

class Logger {
   public:
    int CRITICAL = 50;
    int FATAL = CRITICAL;
    int ERROR = 40;
    int WARNING = 30;
    int WARN = WARNING;
    int INFO = 20;
    int DEBUG = 10;
    int NOTSET = 0;
    void setLevel(int level) { this->level = level; }
    void critical(std::string msg) {
        if (this->level >= CRITICAL) {
            std::cout << "[CRITICAL] " << msg << std::endl;
        }
    }
    void error(std::string msg) {
        if (this->level >= ERROR) {
            std::cout << "[ERROR] " << msg << std::endl;
        }
    }
    void warning(std::string msg) {
        if (this->level >= WARNING) {
            std::cout << "[WARNING] " << msg << std::endl;
        }
    }
    void info(std::string msg) {
        if (this->level >= INFO) {
            std::cout << "[INFO] " << msg << std::endl;
        }
    }
    void debug(std::string msg) {
        if (this->level >= DEBUG) {
            std::cout << "[DEBUG] " << msg << std::endl;
        }
    }

   private:
    int level;
};

inline dict load_yaml(std::string path) {
    dict params;
    std::string line, key, val;
    std::size_t pos;

    std::ifstream stream(path);
    if (stream.fail()) {
        throw std::runtime_error("Failed to open file: " + path);
    }
    while (!stream.eof()) {
        std::getline(stream, line);
        if (line[0] == '#' || line[0] == '\0') {
            continue;
        }
        pos = line.find(':');
        key = line.substr(0, pos);
        pos = line.find_first_not_of(' ', pos + 1);
        val = line.substr(pos, line.size() - pos);
        params[key] = val;
    }
    return params;
}

inline dict load_json(std::string path) {
    dict params;
    throw std::runtime_error("Not implemented yet");
    std::cout << path << std::endl;
    return params;
}

inline dict load_toml(std::string path) {
    dict params;
    throw std::runtime_error("Not implemented yet");
    std::cout << path << std::endl;
    return params;
}
}  // namespace functions

#endif  // ADVLIB_FUNCTIONS_HPP_
