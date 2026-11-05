#include "functions.hpp"

int main() {
    int a[] = {5,9,7,40,41, 4,8,9,42,43,
               5,9,8,44,45, 5,10,4,46,47};
    SortRows(a, 4, 5);
    int expected[] = {4,8,9,42,43, 5,10,4,46,47,
                      5,9,8,44,45, 5,9,7,40,41};
    for (int i = 0; i < 20; ++i) assert(a[i] == expected[i]);
    int b[] = {4,8,9,11,12, 4,8,9,13,14};
    SortRows(b, 2, 5); assert(b[3] == 11 && b[8] == 13);
    assert(!Before(b, b));
    std::cout << "7.1.2 ALL TESTS PASSED\n";
}
