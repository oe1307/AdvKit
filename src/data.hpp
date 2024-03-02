#ifndef SRC_DATA_HPP_
#define SRC_DATA_HPP_

#include <torch/torch.h>

#include <utility>

#include "./base_config.hpp"

namespace advlib {

std::pair<torch::Tensor, torch::Tensor> get_dataset(Config config);
std::pair<torch::Tensor, torch::Tensor> load_cifar10(Config config);

}  // namespace advlib

#endif  // SRC_DATA_HPP_
