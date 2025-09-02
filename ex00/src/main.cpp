#include <iostream>

#include "ansi.h"
#include "whatever.hpp"

int main()
{
    PRINT_SECTION("Testing Function Templates: swap, min, max");

    PRINT_SUBSECTION("1. Testing with int");

    PRINT_TEST("Before swap: a = 2, b = 3");
    int a = 2;
    int b = 3;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    PRINT_TEST("After swap:");
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    PRINT_TEST("min(a, b):");
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;

    PRINT_TEST("max(a, b):");
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    PRINT_SUBSECTION("2. Testing with float");

    PRINT_TEST("Before swap: x = 3.14, y = 2.71");
    float x = 3.14f;
    float y = 2.71f;
    std::cout << "x = " << x << ", y = " << y << std::endl;

    PRINT_TEST("After swap:");
    ::swap(x, y);
    std::cout << "x = " << x << ", y = " << y << std::endl;

    PRINT_TEST("min(x, y):");
    std::cout << "min(x, y) = " << ::min(x, y) << std::endl;

    PRINT_TEST("max(x, y):");
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

    PRINT_SUBSECTION("3. Testing with std::string");

    PRINT_TEST("Before swap: c = 'chaine1', d = 'chaine2'");
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "c = " << c << ", d = " << d << std::endl;

    PRINT_TEST("After swap:");
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;

    PRINT_TEST("min(c, d):");
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;

    PRINT_TEST("max(c, d):");
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    PRINT_SUBSECTION("4. Testing with equal values");

    PRINT_TEST("Testing min and max with equal values:");
    int e = 42;
    int f = 42;
    std::cout << "e = " << e  << ", f = " << f << std::endl;
    std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

    PRINT_SUBSECTION("5. Testing with char");

    PRINT_TEST("Before swap: p = 'a', q = 'z'");
    char p = 'a';
    char q = 'z';
    std::cout << "p = " << p << ", q = " << q << std::endl;

    PRINT_TEST("After swap:");
    ::swap(p, q);
    std::cout << "p = " << p << ", q = " << q << std::endl;

    PRINT_TEST("min(p, q):");
    std::cout << "min(p, q) = " << ::min(p, q) << std::endl;

    PRINT_TEST("max(p, q):");
    std::cout << "max(p, q) = " << ::max(p, q) << std::endl;

    return 0;
}
