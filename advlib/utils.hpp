#ifndef ADVLIB_UTILS_HPP_
#define ADVLIB_UTILS_HPP_

#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "./base_attacker.hpp"

namespace advlib {

using dict = std::map<std::string, std::string>;

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
    return params;
}

inline dict load_toml(std::string path) {
    dict params;
    throw std::runtime_error("Not implemented yet");
    return params;
}

class ConfigParser {
   public:
    explicit ConfigParser(dict setting);
    Config read(std::string path) {
        dict setting;
        std::string extention;

        extention = std::filesystem::path(path).extension();
        if (extention == ".yaml" || extention == ".yml") {
            setting = load_yaml(path);
        } else if (extention == ".json") {
            setting = load_json(path);
        } else if (extention == ".toml") {
            setting = load_toml(path);
        } else {
            throw std::runtime_error("Unsupported file format: " + extention);
        }
        return Config(setting);
    }
};

ConfigParser config_parser();

}  // namespace advlib

#endif  // ADVLIB_UTILS_HPP_
