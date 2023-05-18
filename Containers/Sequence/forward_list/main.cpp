#include <iostream>
#include <vector>
#include "Forward_List.hpp"
#include <forward_list>
#include <chrono>

class A {
    int x;
    int y;
    public:
        A(int x, int y) :
        x(x), y(y) {}
        friend std::ostream& operator<<(std::ostream& os, const A& ob) {
            os << ob.x << " " << ob.y ;
            return os;
        }
};

int main() {
    using namespace my;
    std::vector<int> v{1,2,3,4,5,0,7,8,12};
    Forward_List<int> b(v.begin(), v.end());
    Forward_List<int> ob{12,7,2,3,5,6};
    ob.resize(10, 5);
    for (auto i : ob) {
        std::cout << i << " ";
    }
}