#include "wisdom_collection.h"
#include "wisdom_loader.h"

#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <input.txt> <output.txt> <aphorisms.txt>" << std::endl;
        return 1;
    }

    const std::string input_path = argv[1];
    const std::string output_path = argv[2];
    const std::string aphorisms_path = argv[3];

    WisdomCollection collection;
    std::string error;
    if (!LoadFromFile(input_path, collection, error)) {
        std::cerr << error << std::endl;
        return 1;
    }

    collection.PrintSummary(std::cout);
    collection.PrintContentLengths(std::cout);

    std::ofstream output(output_path);
    if (!output.is_open()) {
        std::cerr << "Unable to open output file: " << output_path << std::endl;
        return 1;
    }

    collection.PrintDetails(output);

    std::ofstream aphorisms_output(aphorisms_path);
    if (!aphorisms_output.is_open()) {
        std::cerr << "Unable to open aphorisms file: " << aphorisms_path << std::endl;
        return 1;
    }

    collection.PrintAphorisms(aphorisms_output);
    return 0;
}
