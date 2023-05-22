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
    std::vector<int> v{1,2,3};
    Forward_List<int> b(v.begin(), v.end());
    Forward_List<int> ob{5,5, 4, 5, 5, 6, 7, 7, 5, 2, 0, 5};
    // ob.splice_after(ob.before_begin(), b);
    // std::cout << b.empty() << std::endl;
    ob.reverse();
    for (auto i : ob) {
        std::cerr << i << " ";
    }
}