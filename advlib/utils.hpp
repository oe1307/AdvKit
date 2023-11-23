#ifndef SRC_UTILS_HPP_
#define SRC_UTILS_HPP_

#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using dict = std::map<std::string, std::string>;

namespace yaml {

dict load(std::string path) {
    dict params;
    std::string line;
    std::size_t pos;
    std::string key;
    std::string val;

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

}  // namespace yaml

#endif  // SRC_UTILS_FUNCTIONS_HPP_