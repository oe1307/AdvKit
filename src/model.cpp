#include "./model.hpp"

#include <torch/torch.h>

advlib::Model advlib::get_model(advlib::Config config) {
    std::string model_path = "storage/cifar10/Linf/Carmon2019Unlabeled_jit.pt";
    Model model = torch::jit::load(model_path);
    model.to(config.device);
    return model;
}
