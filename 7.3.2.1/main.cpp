#include "functions.hpp"

int main() {
    try {
        std::cout << "n, then n*n integers: ";
        int n = ReadSize();
        auto a = std::make_unique<int[]>(n * n);
        auto indices = std::make_unique<int[]>(n);
        Read(a.get(), n * n);
        Print(a.get(), n * n, n);
        int count;
        FindMatches(a.get(), n, indices.get(), count);
        std::cout << "Matching indices (zero-based), count=" << count << '\n';
        if (count) Print(indices.get(), count, count);
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
}
