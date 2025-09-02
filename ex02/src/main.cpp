#include <iostream>

#include "ansi.h"

#include "Array.hpp"

int main()
{
    PRINT_SECTION("Array Class Tests");
	{
	    PRINT_SUBSECTION("Default Constructor");

			PRINT_TEST("Creating an empty array (default constructor)");
			Array<int> emptyArray;
			std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;

		PRINT_SUBSECTION("Parameterized Constructor");

			PRINT_TEST("Creating an array of 5 integers");
			Array<int> intArray(5);
			std::cout << "Size of intArray: " << intArray.size() << std::endl;

			PRINT_TEST("Setting and getting values in intArray");
			for (unsigned int i = 0; i < intArray.size(); ++i) {
				intArray[i] = i * 10;
				std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
			}

	    PRINT_SUBSECTION("Copy Constructor");

			PRINT_TEST("Creating a copy of intArray using copy constructor");
			Array<int> copiedArray(intArray);
			std::cout << "Size of copiedArray: " << copiedArray.size() << std::endl;
			for (unsigned int i = 0; i < copiedArray.size(); ++i) {
				std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;
			}

	    PRINT_SUBSECTION("Assignment Operator");

			PRINT_TEST("Assigning intArray to a new array using assignment operator");
			Array<int> assignedArray;
			assignedArray = intArray;
			std::cout << "Size of assignedArray: " << assignedArray.size() << std::endl;
			for (unsigned int i = 0; i < assignedArray.size(); ++i) {
				std::cout << "assignedArray[" << i << "] = " << assignedArray[i] << std::endl;
			}

	    PRINT_SUBSECTION("Out of Bounds Access");

	    PRINT_TEST("Attempting to access an out-of-bounds index");
			try {
				std::cout << "Trying to access intArray[10]..." << std::endl;
				std::cout << intArray[10] << std::endl;
			} catch (const std::exception& e) {
				std::cerr << "Exception caught: " << e.what() << std::endl;
			}

	    PRINT_SUBSECTION("Testing with Different Types");

			PRINT_TEST("Creating an array of strings");
			Array<std::string> stringArray(3);
			stringArray[0] = "Hello";
			stringArray[1] = "World";
			stringArray[2] = "!";
			for (unsigned int i = 0; i < stringArray.size(); ++i) {
				std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
			}

			PRINT_TEST("Creating a copy of stringArray");
			Array<std::string> copiedStringArray(stringArray);
			for (unsigned int i = 0; i < copiedStringArray.size(); ++i) {
				std::cout << "copiedStringArray[" << i << "] = " << copiedStringArray[i] << std::endl;
			}

	    PRINT_SUBSECTION("Modifying Copies");

			PRINT_TEST("Modifying copiedArray and checking if intArray is affected");
			copiedArray[0] = 100;
			std::cout << "copiedArray[0] after modification: " << copiedArray[0] << std::endl;
			std::cout << "intArray[0] after modification of copiedArray: " << intArray[0] << std::endl;

			PRINT_TEST("Modifying copiedStringArray and checking if stringArray is affected");
			copiedStringArray[0] = "Modified";
			std::cout << "copiedStringArray[0] after modification: " << copiedStringArray[0] << std::endl;
			std::cout << "stringArray[0] after modification of copiedStringArray: " << stringArray[0] << std::endl;

	    PRINT_SUBSECTION("Edge Cases");

			PRINT_TEST("Creating an array of size 0");
			Array<int> zeroArray(0);
			std::cout << "Size of zeroArray: " << zeroArray.size() << std::endl;

			PRINT_TEST("Creating a copy of an empty array");
			Array<int> copiedEmptyArray(emptyArray);
			std::cout << "Size of copiedEmptyArray: " << copiedEmptyArray.size() << std::endl;
	}
    return (0);
}
