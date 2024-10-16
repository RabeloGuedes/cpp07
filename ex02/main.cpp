#include <Array.hpp>
#include <iostream>
#include <cassert>

void	testArrayOfIntegers( void ) {
	Array<int>	integers(1);

	try {
		integers[0] = 5;
		int	firstElement = integers[0];
		firstElement = 6;
		std::cout << "integers at [0]: " << firstElement << std::endl;
		std::cout << "integers size: " << integers.size() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void testArrayOfManyIntegers() {
	Array<int> integers(10);

	try {
		for (int i = 0; i < 10; ++i) {
			integers[i] = i * 10;
		}
		for (int i = 0; i < 10; ++i) {
			std::cout << "integers at [" << i << "]: " << integers[i] << std::endl;
		}
		std::cout << "integers size: " << integers.size() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void testArrayOutOfBounds() {
	Array<int> integers(5);

	try {
		integers[5] = 100; // This should throw an exception
	} catch (std::exception &e) {
		std::cerr << "Out of bounds access: " << e.what() << std::endl;
	}
}

void testArrayNegativeSize() {
	try {
		Array<int> integers(-5); // This should throw an exception
	} catch (std::exception &e) {
		std::cerr << "Negative size: " << e.what() << std::endl;
	}
}

void testArrayNegativeIndex() {
	Array<int> integers(5);

	try {
		integers[-1] = 100; // This should throw an exception
	} catch (std::exception &e) {
		std::cerr << "Negative index access: " << e.what() << std::endl;
	}
}

void testArrayOfStrings() {
	Array<std::string> strings(3);

	try {
		strings[0] = "Hello";
		strings[1] = "World";
		strings[2] = "!";
		for (int i = 0; i < 3; ++i) {
			std::cout << "strings at [" << i << "]: " << strings[i] << std::endl;
		}
		std::cout << "strings size: " << strings.size() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

struct ComplexType {
	int id;
	std::string name;
};

void testArrayOfComplexType() {

	Array<ComplexType> complexArray(2);

	try {
		complexArray[0] = ComplexType();
        complexArray[0].id = 1;
        complexArray[0].name = "First";

        complexArray[1] = ComplexType();
        complexArray[1].id = 2;
        complexArray[1].name = "Second";
		for (int i = 0; i < 2; ++i) {
			std::cout << "complexArray at [" << i << "]: {id: " << complexArray[i].id << ", name: " << complexArray[i].name << "}" << std::endl;
		}
		std::cout << "complexArray size: " << complexArray.size() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void testArrayCopy() {
	Array<int> original(5);
	for (int i = 0; i < 5; ++i) {
		original[i] = i * 2;
	}

	Array<int> copy = original;

	// Modify the copy
	copy[2] = 100;

	// Verify that the original is not affected
	assert(original[2] == 4);
	assert(copy[2] == 100);

	std::cout << "Original array: ";
	for (int i = 0; i < 5; ++i) {
		std::cout << original[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Copied array: ";
	for (int i = 0; i < 5; ++i) {
		std::cout << copy[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "original size: " << original.size() << std::endl;
	std::cout << "copy size: " << copy.size() << std::endl;
}

int	main( void ) {
	testArrayOfIntegers();
	testArrayOfManyIntegers();
	testArrayOutOfBounds();
	testArrayNegativeSize();
	testArrayNegativeIndex();
	testArrayOfStrings();
	testArrayOfComplexType();
	testArrayCopy();
	return (0);
}