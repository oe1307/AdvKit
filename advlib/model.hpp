#ifndef ADVLIB_MODEL_HPP_
#define ADVLIB_MODEL_HPP_

#include <torch/script.h>

namespace advlib {

torch::jit::script::Module get_model();

}  // namespace advlib

#endif  // ADVLIB_MODEL_HPP_
