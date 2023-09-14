#include<iostream>
using namespace std;

// Function to perform Iterative Binary Search in a sorted array 'A' between indices 'l' and 'r' for a given 'key'.
int b_search(int A[], int l, int r, int key) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (key == A[mid]) {
            return mid; // Key found at index 'mid'.
        }

        if (key < A[mid]) {
            r = mid - 1; // Adjust the search range to the left half.
        } else {
            l = mid + 1; // Adjust the search range to the right half.
        }
    }

    return -1; // Key not found in the array.
}

// Function to perform Recursive Binary Search in a sorted array 'A' between indices 'l' and 'r' for a given 'key'.
int b_search_rec(int A[], int l, int r, int key) {
    if (l <= r) {
        int mid = l + (r - l) / 2;

        if (key == A[mid]) {
            return mid; // Key found at index 'mid'.
        }

        if (key < A[mid]) {
            return b_search_rec(A, l, mid - 1, key); // Recursively search the left half.
        } else {
            return b_search_rec(A, mid + 1, r, key); // Recursively search the right half.
        }
    }

    return -1; // Key not found in the array.
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int* arr = new int[size];

    // Input elements of the sorted array.
    for (int i = 0; i < size; i++) {
        cout << "Enter element at position " << i << ": ";
        cin >> arr[i];
    }

    int ans;
    int x;
    cout << "Enter number to search: ";
    cin >> x;
    cout << endl;

    cout << "Enter" << std::endl
        << "(1) to use Binary Search Iteratively" << std::endl
        << "(2) to use Binary Search Recursively" << std::endl;

    int choose;
    cin >> choose;

    if (choose == 1) {
        ans = b_search(arr, 0, size - 1, x); // Call the iterative binary search function.
    } else if (choose == 2) {
        ans = b_search_rec(arr, 0, size - 1, x); // Call the recursive binary search function.
    } else {
        cout << "Invalid choice. Please enter 1 or 2.\n";
    }

    if (ans != -1) {
        cout << x << " is present at index position " << ans;
    } else {
        cout << x << " is not present in the array.";
    }

    delete[] arr; // Deallocate the dynamically allocated memory.

    return 0;
}
