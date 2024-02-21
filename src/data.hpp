#ifndef SRC_DATA_HPP_
#define SRC_DATA_HPP_

#include <torch/torch.h>

#include "./base_config.hpp"

namespace advlib {

torch::Tensor get_dataset(Config config);

}  // namespace advlib

#endif  // SRC_DATA_HPP_
