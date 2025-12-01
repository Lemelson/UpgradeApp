#include "wisdom.h"
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

    WisdomList list;
    std::string error;
    if (!LoadWisdomList(input_path, list, error)) {
        std::cerr << error << std::endl;
        return 1;
    }

    PrintSummary(list, std::cout);
    PrintContentLengths(list, std::cout);

    std::ofstream output(output_path);
    if (!output.is_open()) {
        std::cerr << "Unable to open output file: " << output_path << std::endl;
        return 1;
    }

    PrintDetails(list, output);

    std::ofstream aphorisms_output(aphorisms_path);
    if (!aphorisms_output.is_open()) {
        std::cerr << "Unable to open aphorisms file: " << aphorisms_path << std::endl;
        return 1;
    }

    PrintAphorisms(list, aphorisms_output);

    std::ofstream pair_output(pairs_path);
    if (!pair_output.is_open()) {
        std::cerr << "Unable to open pair file: " << pairs_path << std::endl;
        return 1;
    }

    PrintPairReport(list, pair_output);
    return 0;
}
