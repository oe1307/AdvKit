#include "./base_config.hpp"

std::string advlib::Config::value() {
    std::string message;
    for (auto const& x : this->setting) {
        message += x.first + ": " + x.second + "\n";
    }
    return message;
}
