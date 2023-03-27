#include <iostream>
#include "Vector.h"
#include <vector>

class A {
	public:
		A() = delete;
		A(int x) {
			std::cout << "A" << " ";
		}
};

int main() {
	using namespace my;
	// Vector<bool> b(3, true);
	// Vector<bool> a(b);
	// a = {1,1,0,0,1,0,1};
	// for (auto j = a.cend(); j != a.cbegin(); --j) {
	// 	std::cout << *j << " ";
	// }
	// // auto j = a.cend();
	// // --j;
	// // std::cout << *j << std::endl;
	// for (auto i = a.begin(); i != a.end(); ++i) {
	// 	std::cout << *i;
	//  }
	// Vector<A> ob;
	// A b(6);
	// ob.push_back(b);
	std::vector<A> ob;
	A b(6);
	ob.push_back(b);
	ob.push_back(4);
}
