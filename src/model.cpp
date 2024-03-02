#include "./model.hpp"

#include <torch/torch.h>

advlib::Model advlib::get_model(advlib::Config config) {
    std::string model_path = config.model;
    Model model = torch::jit::load(model_path);
    model.to(config.device);
    return model;
}
