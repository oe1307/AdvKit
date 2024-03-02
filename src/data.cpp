#include "./data.hpp"

// for ImageNet: #include <opencv2/opencv.hpp>

std::pair<torch::Tensor, torch::Tensor> advlib::get_dataset(
    advlib::Config config) {
    auto [data, label] = load_cifar10(config);
    return {data, label};
}

std::pair<torch::Tensor, torch::Tensor> advlib::load_cifar10(Config config) {
    torch::Tensor data;
    torch::Tensor label = torch::empty(config.n_examples, torch::kUInt8);
    return {data, label};
}
