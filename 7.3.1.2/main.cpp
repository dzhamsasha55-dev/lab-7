#include "functions.hpp"

int main() {
    try {
        std::cout << "n, then n*n integers: ";
        int n = ReadSize();
        auto a = std::make_unique<int[]>(n * n);
        Read(a.get(), n * n);
        Print(a.get(), n * n, n);
        std::cout << "Sum=" << SumNegativeRows(a.get(), n) << '\n';
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
}
