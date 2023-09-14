#include<iostream>
using namespace std;

// Function to perform linear search for an element 'k' in an array 'A' of size 'n'.
bool b_search(int A[], int n, int k) {
    int flag = 0; // Initialize a flag variable to 0.

    // Loop through the array to check if 'k' is equal to any element in 'A'.
    for (int i = 0; i < n; i++) {
        if (k == A[i]) {
            flag = 1; // Set the flag to 1 if 'k' is found in 'A'.
        }
    }

    // Check the flag to determine if 'k' was found in the array.
    if (flag == 1) {
        return true; // 'k' is found in the array, return true.
    }

    return false; // 'k' is not found in the array, return false.
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int k = 7;

    // Call the b_search function to search for 'k' in 'arr'.
    bool ans = b_search(arr, 5, 7);

    if (ans == true) {
        cout << k << " is in the array.";
    } else {
        cout << k << " is not in the array.";
    }

    return 0;
}