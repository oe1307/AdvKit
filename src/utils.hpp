#ifndef SRC_UTILS_HPP_
#define SRC_UTILS_HPP_

#include <map>
#include <string>

namespace advlib {

using dict = std::map<std::string, std::string>;

dict load_yaml(std::string path);
dict load_json(std::string path);
dict load_toml(std::string path);

}  // namespace advlib

#endif  // SRC_UTILS_HPP_
