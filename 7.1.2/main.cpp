#include "functions.hpp"

int main() {
    try {
        int R[40];
        std::mt19937 rng(7);
        Generate(R, 40, 4, 51, rng);
        Print(R, 40, 5);
        SortRows(R, 8, 5);
        std::cout << "Sorted matrix\n";
        Print(R, 40, 5);
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
}
