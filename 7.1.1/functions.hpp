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

bool Selected(int x, int i, int j) {
    return !(x % 2 != 0 || (i % 3 == 0 && j % 3 == 0));
}
int Count(const int* a, int rows, int cols) {
    int result = 0;
    Walk(0, rows * cols, [&](int p) {
        if (Selected(a[p], p / cols, p % cols)) ++result;
    });
    return result;
}
int Sum(const int* a, int rows, int cols) {
    int result = 0;
    Walk(0, rows * cols, [&](int p) {
        if (Selected(a[p], p / cols, p % cols)) result += a[p];
    });
    return result;
}
void Replace(int* a, int rows, int cols) {
    Walk(0, rows * cols, [&](int p) {
        if (Selected(a[p], p / cols, p % cols)) a[p] = 0;
    });
}
