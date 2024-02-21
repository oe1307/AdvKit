#ifndef SRC_MODEL_HPP_
#define SRC_MODEL_HPP_

#include <torch/script.h>

#include "./base_config.hpp"

namespace advlib {

using Model = torch::jit::script::Module;

Model get_model(Config config);

}  // namespace advlib

#endif  // SRC_MODEL_HPP_
