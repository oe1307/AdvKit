#include "./data.hpp"

// for ImageNet: #include <opencv2/opencv.hpp>

std::pair<torch::Tensor, torch::Tensor> advlib::get_dataset(
    advlib::Config config) {
    torch::Tensor data, label;
    // TODO: implement the dataset loader
    config.value();
    //
    return {data, label};
}
