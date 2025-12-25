#include "cli/CLInterface.hpp"
#include "fmt/color.h"
#include <memory>


int main(int argc, char *argv[]) {
    try {
        const auto cli = std::make_unique<mmqli::cli::CLInterface>(argc, argv);
        try {
            cli->start_cli();
        } catch (const std::runtime_error &re) {
            fmt::print(fg(fmt::color::red), "Exception(s) Thrown: {}\n", re.what());
            return EXIT_FAILURE;
        }
    } catch (const std::runtime_error &re) {
        fmt::print(fg(fmt::color::red), "Exception Thrown: {}\n", re.what());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
