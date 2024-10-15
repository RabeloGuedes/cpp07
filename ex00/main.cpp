#include <whatever.hpp>
#include <iostream>
#include <cassert>

void test_swap( void ) {
	int a = 2, b = 3;
	::swap(a, b);
	assert(a == 3 && b == 2);

	std::string c = "chaine1", d = "chaine2";
	::swap(c, d);
	assert(c == "chaine2" && d == "chaine1");
}

void test_min( void ) {
	int a = 2, b = 3;
	assert(::min(a, b) == a);

	std::string c = "chaine1", d = "chaine2";
	assert(::min(c, d) == c);
}

void test_max( void ) {
	int a = 2, b = 3;
	assert(::max(a, b) == b);

	std::string c = "chaine1", d = "chaine2";
	assert(::max(c, d) == d);
}

int main( void ) {
	test_swap();
	test_min();
	test_max();

	std::cout << "All tests passed!" << std::endl;
	return 0;
}