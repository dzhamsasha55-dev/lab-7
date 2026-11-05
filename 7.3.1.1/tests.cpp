#include "functions.hpp"

int main() {
    int a[] = {1,2,3, 2,5,6, 3,7,9}; int out[3], count;
    FindMatches(a, 3, out, count); assert(count == 1 && out[0] == 0);
    int b[] = {1,2,2,3}; FindMatches(b, 2, out, count);
    assert(count == 2 && out[0] == 0 && out[1] == 1);
    int c[] = {1,2,3,4}; FindMatches(c, 2, out, count); assert(count == 0);
    int d[] = {0}; FindMatches(d, 1, out, count); assert(count == 1);
    std::cout << "7.3.1.1 ALL TESTS PASSED\n";
}
