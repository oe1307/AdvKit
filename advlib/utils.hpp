#ifndef ADVLIB_UTILS_HPP_
#define ADVLIB_UTILS_HPP_

#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

namespace advlib {

using dict = std::map<std::string, std::string>;

inline void fix_seed(int seed) {
    std::cout << seed << std::endl;
    throw std::runtime_error("Not implemented yet");
}

class Logger {
   public:
    enum Level {
        CRITICAL = 50,
        FATAL = CRITICAL,
        ERROR = 40,
        WARNING = 30,
        WARN = WARNING,
        INFO = 20,
        DEBUG = 10,
        NOTSET = 0
    };
    void setLevel(Level level) { this->level = level; }
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

Logger logger();

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

class BaseConfig {
public:
    explicit BaseConfig(dict setting);
};

class ConfigParser {
   public:
    BaseConfig read(std::string path) {
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
        return BaseConfig(setting);
    }

   private:
    BaseConfig config;
};

ConfigParser config_parser();

class ProgressBar {
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

   private:
    Logger logger;
    int total, length, iter, percent;
    std::string fmsg, bmsg, bar;
};

}  // namespace advlib

#endif  // ADVLIB_UTILS_HPP_
