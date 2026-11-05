#include "functions.hpp"

int main() {
    int a[] = {3,-2,7, 5,4,9, -1,0,2};
    assert(MaxOfRowMins(a, 3, 3) == 4);
    int b[] = {-5,-2,-8,-3}; assert(MaxOfRowMins(b, 2, 2) == -5);
    int c[] = {9}; assert(MaxOfRowMins(c, 1, 1) == 9);
    int d[] = {3,8,-1}; assert(MaxOfRowMins(d, 3, 1) == 8);
    bool rejected = false;
    try { MaxOfRowMins(a, 0, 3); } catch (const std::invalid_argument&) { rejected = true; }
    assert(rejected);
    std::cout << "7.2.1 ALL TESTS PASSED\n";
}
