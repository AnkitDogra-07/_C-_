#include<iostream>
#include "../Boilerplate/swap.hpp" // Include a custom swap header if available

// Function to perform Iterative Selection Sort on an array 'A' of size 'n'.
void selection_sort(int A[], int n) {
    for (int i = 0; i < n; i++) {
        int key = i;
        // Find the index of the minimum element in the unsorted part of the array.
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[key]) {
                key = j;
            }
        }

        // Swap the minimum element with the current element.
        if (key != i) {
            swap(A[i], A[key]);
        }
    }
}

// Function to perform Recursive Selection Sort on an array 'A' from 'start' to 'n'.
void selection_sort_rec(int A[], int start, int n) {
    int key = start;
    int j = start + 1;

    if (start >= n - 1) {
        return; // Base case: The entire array is sorted.
    }

    // Find the index of the minimum element in the unsorted part of the array.
    while (j < n) {
        if (A[j] < A[key]) {
            key = j;
        }
        j++;
    }

    // Swap the minimum element with the element at 'start'.
    if (key != start) {
        swap(A[key], A[start]);
    }

    // Recursively sort the rest of the array.
    return selection_sort_rec(A, start + 1, n);
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
              << "(1) to use Selection Sort Iteratively" << std::endl
              << "(2) to use Selection Sort Recursively" << std::endl;

    int choose;
    std::cin >> choose;

    if (choose == 1) {
        selection_sort(arr, size); // Call the iterative selection sort function.
    } else if (choose == 2) {
        selection_sort_rec(arr, 0, size); // Call the recursive selection sort function.
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
