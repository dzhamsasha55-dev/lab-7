#include "functions.hpp"

int main() {
    try {
        constexpr int rows = 3, cols = 4;
        int a[rows * cols];
        std::mt19937 rng(7);
        Generate(a, rows * cols, -20, 20, rng);
        Print(a, rows * cols, cols);
        std::cout << "Max of row minima=" << MaxOfRowMins(a, rows, cols) << '\n';
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
}
