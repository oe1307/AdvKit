
#ifndef ADVLIB_DATA_HPP_
#define ADVLIB_DATA_HPP_

#include <torch/torch.h>

namespace advlib {

torch::data::Dataset get_dataset();

}  // namespace advlib

#endif  // ADVLIB_DATA_HPP_
