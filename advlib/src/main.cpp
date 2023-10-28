#include <ATen/Parallel.h>
#include <c10/cuda/CUDAFunctions.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "./selector/attacker.hpp"
#include "./selector/config.hpp"
#include "./utils/argparse.hpp"
#include "./utils/functions.hpp"

dict argparser(int argc, char *argv[]) {
    argparse::ArgumentParser parser;
    dict args;
    parser.add_argument("-p", "--params").required().help("path to yaml file");
    parser.add_argument("-g", "--device").required().help("gpu id");
    parser.add_argument("-t", "--thread")
        .default_value("1")
        .help("number of threads");
    parser.add_argument("-u", "--update")
        .nargs('*')
        .help("params to update, e.g.)  -u iter=100 n_examples=1000");
    args = parser.parse_args(argc, argv);
    return args;
}

void attack(Config config) {
    c10::cuda::set_device(config.device);
    at::set_num_threads(config.thread);
    config.savedir =
        utils::rename_dir(config.basedir + "/result/" + config.attacker + "/" +
                          config.model + "/result");
}

int main(int argc, char *argv[]) {
    try {
        dict args = argparser(argc, argv);
        dict params = yaml::load(args["params"]);
        Config *config = get_config(args, params);
        attack(*config);
    } catch (const std::exception &error) {
        std::filesystem::create_directory("../result");
        std::ofstream stream("../result/error.txt");
        stream << error.what() << std::endl;
        stream.close();
        std::cerr << error.what() << std::endl;
        return 1;
    }
    return 0;
}
