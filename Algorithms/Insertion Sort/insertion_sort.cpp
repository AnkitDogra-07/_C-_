#include "../Boilerplate/swap.hpp" // Include a custom swap header if available
#include <iostream>
#include <cstdlib> // Include the <cstdlib> header for dynamic memory allocation

// Function to perform Iterative Insertion Sort on an array 'A' of size 'n'.
void insertionSort(int A[], int n) {
    for (int pos = 1; pos < n; pos++) {
        int nextpos = pos;
        // Move the element at 'nextpos' to its correct position in the sorted part of the array.
        while (nextpos > 0 && A[nextpos] < A[nextpos - 1]) {
            // Swap the elements if they are out of order.
            swap(A[nextpos], A[nextpos - 1]);
            nextpos--;
        }
    }
}

// Function to perform Recursive Insertion Sort on an array 'A' from 'start' to 'n'.
void insertionSort_rec(int A[], int start, int n) {
    if (start > n - 1) {
        return; // Base case: The entire array is sorted.
    }

    int pos = start;
    // Move the element at 'pos' to its correct position in the sorted part of the array.
    while (pos > 0 && A[pos] < A[pos - 1]) {
        // Swap the elements if they are out of order.
        swap(A[pos], A[pos - 1]);
        pos--;
    }

    // Recursively sort the rest of the array.
    insertionSort_rec(A, start + 1, n);
}

int main() {
    int size;
    std::cout << "Enter length of array: ";
    std::cin >> size;
    int* arr = new int[size]; // Allocate dynamic memory for the array.

    // Input elements of the array.
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Enter" << std::endl
              << "(1) to use Insertion Sort Iteratively" << std::endl
              << "(2) to use Insertion Sort Recursively" << std::endl;

    int choose;
    std::cin >> choose;

    if (choose == 1) {
        insertionSort(arr, size); // Call the iterative insertion sort function.
    } else if (choose == 2) {
        insertionSort_rec(arr, 0, size); // Call the recursive insertion sort function.
    } else {
        std::cout << "Invalid choice. Please enter 1 or 2.\n";
    }

    std::cout << "After sorting:\n";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    delete[] arr; // Deallocate the dynamically allocated memory.

    return 0;
}
