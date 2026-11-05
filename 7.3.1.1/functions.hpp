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

bool EqualRowColumn(const int* a, int n, int k) {
    bool equal = true;
    Walk(0, n, [&](int j) {
        if (a[k * n + j] != a[j * n + k]) equal = false;
    });
    return equal;
}
// Output parameters hold zero-based indices and their count.
void FindMatches(const int* a, int n, int* indices, int& count) {
    count = 0;
    Walk(0, n, [&](int k) {
        if (EqualRowColumn(a, n, k)) indices[count++] = k;
    });
}
