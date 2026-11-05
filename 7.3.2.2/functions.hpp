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
void Read(int* a, int n) {
    Walk(0, n, [&](int i) {
        if (!(std::cin >> a[i]) || a[i] < -1000 || a[i] > 1000)
            throw std::runtime_error("Element outside [-1000,1000]");
    });
}
void Print(const int* a, int n, int columns) {
    Walk(0, n, [&](int i) {
        std::cout << std::setw(7) << a[i];
        if ((i + 1) % columns == 0) std::cout << '\n';
    });
}
int ReadSize() {
    int n;
    if (!(std::cin >> n) || n < 1 || n > 100)
        throw std::runtime_error("Size must be in [1,100]");
    return n;
}

bool HasNegative(const int* row, int n) {
    bool found = false;
    Walk(0, n, [&](int j) { if (row[j] < 0) found = true; });
    return found;
}
int RowSum(const int* row, int n) {
    int result = 0;
    Walk(0, n, [&](int j) { result += row[j]; });
    return result;
}
int SumNegativeRows(const int* a, int n) {
    int result = 0;
    Walk(0, n, [&](int i) {
        if (HasNegative(a + i * n, n)) result += RowSum(a + i * n, n);
    });
    return result;
}
