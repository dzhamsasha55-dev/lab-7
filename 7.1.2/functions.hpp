#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <random>
#include <optional>
#include <type_traits>
#include <stdexcept>
#include <limits>
#include <utility>
#include <cassert>

// Execute an action for each index in [begin, end).
template<class Action>
void Walk(int begin, int end, Action action) {
    for (int i = begin; i < end; ++i) action(i);
}
void Print(const int* a, int n, int columns) {
    Walk(0, n, [&](int i) {
        std::cout << std::setw(7) << a[i];
        if ((i + 1) % columns == 0) std::cout << '\n';
    });
}
void Generate(int* a, int n, int low, int high,
              std::mt19937& rng) {
    std::uniform_int_distribution<int> distribution(low, high);
    Walk(0, n, [&](int i) { a[i] = distribution(rng); });
}

// Lexicographic order: first ascending, second and third descending.
bool Before(const int* a, const int* b) {
    if (a[0] != b[0]) return a[0] < b[0];
    if (a[1] != b[1]) return a[1] > b[1];
    return a[2] > b[2];
}
void SortRows(int* a, int rows, int cols) {
    Walk(0, rows - 1, [&](int pass) {
        Walk(0, rows - 1 - pass, [&](int i) {
            if (Before(a + (i + 1) * cols, a + i * cols))
                Walk(0, cols, [&](int j) {
                    std::swap(a[i * cols + j], a[(i + 1) * cols + j]);
                });
        });
    });
}
