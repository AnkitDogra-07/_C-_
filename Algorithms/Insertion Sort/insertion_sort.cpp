#include "../Boilerplate/swap.hpp"
#include <iostream>

int main() {
    int x = 10, y = 20;
    int* a = &x;  // Initialize a to point to the address of x
    int* b = &y;  // Initialize b to point to the address of y

    std::cout << "Before swapping:\n";
    std::cout << "*a: " << *a << "\n";
    std::cout << "*b: " << *b << "\n";

    swap(a, b);

    std::cout << "After swapping:\n";
    std::cout << "*a: " << *a << "\n";
    std::cout << "*b: " << *b << "\n";

    return 0;
}
