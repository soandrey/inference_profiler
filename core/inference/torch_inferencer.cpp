#include "torch_inferencer.hpp"

#include <iostream>

TorchInferencer::TorchInferencer() {
    std::cout << "Class" << std::endl;
}

std::string TorchInferencer::say_hello() {
    return "HelloTorch";
}
