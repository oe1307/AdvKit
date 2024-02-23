#include "./data.hpp"

std::pair<torch::Tensor, torch::Tensor> advlib::get_dataset(
    advlib::Config config) {
    torch::Tensor data, label;

    std::string tmp = config.value();

    return {data, label};
}
