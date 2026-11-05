#include "functions.hpp"

int main() {
    int a[] = {1,-2,3, 4,5,6, -7,0,2};
    assert(SumNegativeRows(a, 3) == -3);
    int b[] = {1,2,0,3}; assert(SumNegativeRows(b, 2) == 0);
    int c[] = {-1,-2,-3,-4}; assert(SumNegativeRows(c, 2) == -10);
    int d[] = {-7}; assert(SumNegativeRows(d, 1) == -7);
    int e[] = {-1,9,3,4}; assert(SumNegativeRows(e, 2) == 8);
    std::cout << "7.3.2.2 ALL TESTS PASSED\n";
}
