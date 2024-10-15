#include <iter.hpp>
#include <iostream>
#include <sstream>
#include <cassert>

template <typename T>
void print(T const &x) {
    std::cout << x << " ";
}

template <typename T>
void increment(T const &x) {
	const_cast<T &>(x)++;
}

void test_intArray( void ) {
    int intArray[] = {1, 2, 3, 4, 5};
    std::ostringstream oss;
    std::streambuf *coutbuf = std::cout.rdbuf(oss.rdbuf());

    iter(intArray, 5, print);
    std::cout << std::endl;

    std::cout.rdbuf(coutbuf);
    std::string expected = "1 2 3 4 5 \n";
    assert(oss.str() == expected);
}

void test_strArray( void ) {
    std::string strArray[] = {"one", "two", "three", "four", "five"};
    std::ostringstream oss;
    std::streambuf *coutbuf = std::cout.rdbuf(oss.rdbuf());

    iter(strArray, 5, print);
    std::cout << std::endl;

    std::cout.rdbuf(coutbuf);
    std::string expected = "one two three four five \n";
    assert(oss.str() == expected);
}

void test_incrementArray( void ) {
    int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, increment);

    int expectedArray[] = {2, 3, 4, 5, 6};
    for (int i = 0; i < 5; ++i) {
        assert(intArray[i] == expectedArray[i]);
    }
}

int main( void ) {
    test_intArray();
    test_strArray();
    test_incrementArray();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}