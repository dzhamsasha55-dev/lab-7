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

// Recursive traversal; the empty interval is the base case.
template<class Action>
void Walk(int begin, int end, Action action) {
    if (begin >= end) return;
    action(begin);
    Walk(begin + 1, end, action);
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

int RowMin(const int* a, int cols) {
    int result = a[0];
    Walk(1, cols, [&](int j) { if (a[j] < result) result = a[j]; });
    return result;
}
int MaxOfRowMins(const int* a, int rows, int cols) {
    if (rows <= 0 || cols <= 0)
        throw std::invalid_argument("Empty matrix");
    int result = RowMin(a, cols);
    Walk(1, rows, [&](int i) {
        int value = RowMin(a + i * cols, cols);
        if (value > result) result = value;
    });
    return result;
}
