#include<iostream>  // Include the standard input/output stream library.
#include<vector>     // Include the vector container class.
#include<algorithm>  // Include the algorithm library for the swap function.
using namespace std; // Use the standard namespace for convenience.

// Function to partition the array A between indices low and high.
int partition(vector<int>& A, int low, int high){
    // Select the pivot element as the last element of the array.
    int pivot = A[high];

    // Initialize the index of the smaller element.
    int i = low - 1;

    // Iterate through the elements from low to high-1.
    for(int j=low; j<high; j++){
        // If the current element is less than or equal to the pivot, swap it with the element at index i+1.
        if(A[j] <= pivot){
            i++;
            swap(A[i], A[j]);
        }
    }

    // Swap the pivot element (A[high]) with the element at index i+1.
    swap(A[i+1], A[high]);

    // Return the index of the pivot element in its sorted position.
    return (i+1);
}

// Function to perform the Quick Sort algorithm on the array A.
void quick_sort(vector<int>& A, int left, int right){
    // Base case: If the left index is less than the right index.
    if(left < right){
        // Partition the array and get the pivot index.
        int p = partition(A, left, right);
        
        // Recursively sort the subarrays to the left and right of the pivot.
        quick_sort(A, left, p-1);
        quick_sort(A, p, right);
    }
}

int main(){
    int size;

    // Prompt the user to enter the size of the array.
    cout << "Enter Size of Array:";
    cin >> size;

    // Create a vector to store the elements of the array.
    vector<int> arr(size);

    // Prompt the user to enter each element of the array.
    for(int i=0; i<size; i++){
        cout << "Element at index position " << i << " : ";
        cin >> arr[i];
    }

    cout << endl;

    // Display the original array before sorting.
    cout << "Array before Quick Sort" << endl;    
    for(int i=0; i<size; i++){
        cout << arr[i] << "\t";
    }

    // Call the quick_sort function to sort the array.
    quick_sort(arr, 0, size - 1);

    cout << endl;

    // Display the sorted array after Quick Sort.
    cout << "Array after Quick Sort" << endl;    
    for(int i=0; i<size; i++){
        cout << arr[i] << "\t";
    }
}
