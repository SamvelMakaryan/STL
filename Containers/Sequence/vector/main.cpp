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
	Vector<A> ob {A(1),A(2),A(3),A(4)};
	Vector<A> ob2 {A(11),A(22),A(33),A(44),A(44)};
	ob.assign(ob2.begin(), ob2.end());
	std::cout << ob.size() << " " << ob.capacity() << " ";
	// std::vector<A> ob {A(1),A(2),A(3),A(4)};
	// Vector<int> ob {1,2,3,4,6};
	// ob.emplace(ob.begin() + 4, 9);
	// ob.insert(ob.begin() + 5, {9,9,9});
	// Vector<int> ob2 {5,7,8,9,88};
	// Vector<A> ob {A(1),A(2),A(3),A(4)};
	
	// ob.insert(ob.begin() + 2, x);

	//###iteraotrs operator-
	// ob.insert(ob.begin() + 3, ob2.begin() +1, ob2.begin() + 4);
	// try {ob.insert(ob.end(), 9);} catch(...) {std::cout << "a";}
	// ob2.insert(ob2.begin() + 1, 5, 9);
	// std::vector<A> ob2 {A(1),A(2),A(3),A(4)};
	// ob2.insert(ob2.begin() + 2, A(5));
	for (auto& i : ob)
		std::cout << i;
		std::cout << std::endl;
	// for (auto& i : ob2) {
	// 	std::cout << i;
	// }
	// std::cout << std::endl;
	// Vector<int> b(ob.begin(), ob.begin() + 4);
	// ob.push_back(4);
	// b = {1,2,1,1};
	// b.resize(15, 6);
	// for (auto& i: b)
	// std::cout << i;
	// std::cout << std::endl << b.size() << "  " << b.capacity();
	// ob.resize(5);


	
}
