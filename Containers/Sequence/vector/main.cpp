#include <iostream>
#include "Vector.hpp"
#include <vector>

class A {
	public:
		A() : x(0) {std::cout <<"A default\n";};
		A(int x) : x(x) {
			std::cout << "A par \n";
		}
		A(A&& oth) : x(std::move(oth.x)) {std::cout <<"A move\n";}
		A(const A& oth): x(oth.x) {std::cout <<"A copy\n";}
		A& operator=(const A&) {std::cout << "A =\n"; return*this;}
		A& operator=(A&&) {std::cout << "A move=\n"; return*this;}
		friend std::ostream& operator<<(std::ostream& os, const A& ob) {
			os << ob.x;
			return os;
		}
	private:
		int x;
};

int main() {
	using namespace my;
	Vector<bool> a {1,1,1,0,0,1};
	// Vector<bool> a;
	// a.resize(5,1);
	for (int i = 0; i < a.size(); ++i) {
		std::cout << a[i] << " ";
	}
}
