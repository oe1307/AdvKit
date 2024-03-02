#include "./model.hpp"

#include <torch/torch.h>

advlib::Model advlib::get_model(advlib::Config config) {
    std::string model_path = "tests/example/test_model.pth";
    Model model = torch::jit::load(model_path);
    model.to(config.device);
    return model;
}
