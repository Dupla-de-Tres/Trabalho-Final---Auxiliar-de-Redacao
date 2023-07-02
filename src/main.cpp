#include <iostream>
#include <ctime>
#include "read.hpp"

int main() {
    std::clock_t start = std::clock();

    ReadFile();

    std::clock_t end = std::clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "\nTempo total de execução: " << duration << " segundos." << std::endl;

    return 0;
}

