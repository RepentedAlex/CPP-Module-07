#include <iostream>

#include "ansi.h"
#include "iter.hpp"

void printInt(const int& element) {
    std::cout << element << " ";
}

void incrementInt(int& element) {
    element += 1;
}

void doubleInt(int& element) {
    element *= 2;
}

// Non-template test functions for std::string
void printString(const std::string& element) {
    std::cout << element << " ";
}

void toUpperCase(std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = toupper(str[i]);
    }
}

class testClass {
public:
    int value;
    testClass(int v = 0) : value(v) {}
};

std::ostream& operator<<(std::ostream& os, const testClass& obj) {
	os << "testClass(" << obj.value << ")";
	return os;
}

void printtestClass(const testClass& obj) {
    std::cout << obj << " ";
}

void incrementtestClass(testClass& obj) {
    obj.value += 1;
}

int main() {
    PRINT_SECTION("Basic Tests");

    PRINT_SUBSECTION("int array");
    {
        int intArray[] = {1, 2, 3, 4, 5};
        unsigned int length = 5;

        PRINT_TEST("Printing elements:");
        iter(intArray, length, printInt);
        std::cout << std::endl;

        PRINT_TEST("Incrementing elements:");
        iter(intArray, length, incrementInt);
        iter(intArray, length, printInt);
        std::cout << std::endl;

        PRINT_TEST("Doubling elements:");
        iter(intArray, length, doubleInt);
        iter(intArray, length, printInt);
        std::cout << std::endl;
    }

    PRINT_SUBSECTION("std::string array");
    {
        std::string strArray[] = {"hello", "world", "!"};
        unsigned int length = 3;

        PRINT_TEST("Printing elements:");
        iter(strArray, length, printString);
        std::cout << std::endl;

        PRINT_TEST("Converting to uppercase:");
        iter(strArray, length, toUpperCase);
        iter(strArray, length, printString);
        std::cout << std::endl;
    }

    PRINT_SECTION("Edge Cases");

    PRINT_SUBSECTION("Empty array");
    {
        int emptyArray[] = {};
        unsigned int length = 0;

        PRINT_TEST("Printing elements of empty array:");
        iter(emptyArray, length, printInt);
        std::cout << std::endl;
    }

    PRINT_SUBSECTION("Single element array");
    {
        int singleArray[] = {42};
        unsigned int length = 1;

        PRINT_TEST("Printing single element:");
        iter(singleArray, length, printInt);
        std::cout << std::endl;

        PRINT_TEST("Incrementing single element:");
        iter(singleArray, length, incrementInt);
        iter(singleArray, length, printInt);
        std::cout << std::endl;
    }

    PRINT_SECTION("Custom Class");

    PRINT_SUBSECTION("User-defined type");
    {
        testClass myArray[] = {testClass(1), testClass(2), testClass(3)};
        unsigned int length = 3;

        PRINT_TEST("Printing testClass elements:");
        iter(myArray, length, printtestClass);
        std::cout << std::endl;

        PRINT_TEST("Incrementing testClass elements:");
        iter(myArray, length, incrementtestClass);
        iter(myArray, length, printtestClass);
        std::cout << std::endl;
    }

    return (0);
}
