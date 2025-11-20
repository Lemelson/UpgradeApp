#include "wisdom_collection.h"
#include "wisdom_loader.h"
#include "multimethod.h"

#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0]
                  << " <input.txt> <output.txt> <aphorisms.txt> <pairs.txt>" << std::endl;
        return 1;
    }

    const std::string input_path = argv[1];
    const std::string output_path = argv[2];
    const std::string aphorisms_path = argv[3];
    const std::string pairs_path = argv[4];

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

    std::ofstream pair_output(pairs_path);
    if (!pair_output.is_open()) {
        std::cerr << "Unable to open pair file: " << pairs_path << std::endl;
        return 1;
    }

    PrintPairReport(collection, pair_output);
    return 0;
}
