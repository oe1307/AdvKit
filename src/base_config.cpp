#include "./base_config.hpp"

#include <set>

void advlib::Config::check_keys(advlib::dict setting) {
    /*check setting contains a certain keys*/
    std::set<std::string> keys = {"attacker",   "norm",  "epsilon",
                                  "dataset",    "model", "n_examples",
                                  "batch_size", "device"};
    for (auto const& x : keys) {
        if (setting.find(x) == setting.end()) {
            throw std::invalid_argument("Setting does not contain key: " + x);
        }
    }
}

std::string advlib::Config::value() {
    std::string message;
    for (auto const& x : this->setting) {
        message += x.first + ": " + x.second + "\n";
    }
    return message;
}
