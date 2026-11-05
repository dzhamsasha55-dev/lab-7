#include "functions.hpp"

int main() {
    int a[40]; for (int& x : a) x = 4;
    assert(Count(a, 8, 5) == 34); assert(Sum(a, 8, 5) == 136);
    Replace(a, 8, 5); assert(a[0] == 4 && a[3] == 4 && a[1] == 0);
    assert(a[3 * 5] == 4 && a[6 * 5 + 3] == 4);
    for (int& x : a) x = 5;
    assert(Count(a, 8, 5) == 0); assert(Sum(a, 8, 5) == 0);
    assert(Selected(6, 0, 1)); assert(!Selected(6, 0, 0));
    std::cout << "7.1.1 ALL TESTS PASSED\n";
}
