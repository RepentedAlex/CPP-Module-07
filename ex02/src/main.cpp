#include "Array.hpp"
#include <iostream>

int main() {
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	Array<int> arr(5);
	std::cout << "Array size: " << arr.size() << std::endl;

	for (size_t i = 0; i < arr.size(); ++i) {
		arr[i] = i * 10;
	}

	Array<int> copy(arr);
	std::cout << "Copy array size: " << copy.size() << std::endl;

	// Test assignment operator
	Array<int> assign;
	assign = arr;
	std::cout << "Assigned array size: " << assign.size() << std::endl;

	// Test out-of-bounds access
	try {
		std::cout << arr[10] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return (0);
}

