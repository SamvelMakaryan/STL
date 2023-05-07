#include "Array.hpp"
#include <iostream>

int main() {
    my::Array<int, 6> ob{88,99,8};
    my::Array<int, 6> bb{1,2,3,4,5,6};
    bb.fill(3);
    ob.swap(bb);
    for (auto & i : bb) {
        std::cout << i << " ";
    }
}