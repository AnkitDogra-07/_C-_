#include "../Boilerplate/swap.hpp"
#include <iostream>
#include <cstdlib> // Include the <cstdlib> header for dynamic memory allocation

// Iterative Insertion Sort
void insertionSort(int A[], int n) {
    for (int pos = 1; pos < n; pos++) {
        int nextpos = pos;
        while (nextpos > 0 && A[nextpos] < A[nextpos - 1]) {
            swap(A[nextpos], A[nextpos - 1]);
            nextpos--;
        }
    }
}

// Recursive Insertion Sort
void insertionSort_rec(int A[], int start, int n) {
    if (start >= n - 1) {
        return;
    }

    int pos = start;
    while (pos > 0 && A[pos] < A[pos - 1]) {
        swap(A[pos], A[pos - 1]);
        pos--;
    }

    insertionSort_rec(A, start + 1, n);
}

int main() {
    int size;
    std::cout << "Enter length of array: ";
    std::cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Enter" << std::endl
              << "(1) to use Insertion Sort Iteratively" << std::endl
              << "(2) to use Insertion Sort Recursively" << std::endl;

    int choose;
    std::cin >> choose;

    if (choose == 1) {
        insertionSort(arr, size);
    } else if (choose == 2) {
        insertionSort_rec(arr, 0, size);
    } else {
        std::cout << "Invalid choice. Please enter 1 or 2.\n";
    }

    std::cout << "After sorting:\n";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    delete[] arr;

    return 0;
}
