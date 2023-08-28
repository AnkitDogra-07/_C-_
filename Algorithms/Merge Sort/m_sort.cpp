#include<iostream>
#include<vector>
using namespace std;

// Function to merge two sorted arrays A and B into C.
void merge(vector<int>& A, vector<int>& B, vector<int>& C){
    int m = A.size();
    int n = B.size();
    int i = 0, j = 0, k = 0;

    // Merge elements from A and B into C while maintaining sorted order.
    while(i < m && j < n){
        if(A[i] <= B[j]){
            C[k] = A[i]; 
            i++;
        }
        else{
            C[k] = B[j]; 
            j++; 
        }
        k++;
    }

    // Copy remaining elements from A and B into C if any.
    while(i < m){
        C[k] = A[i]; 
        i++; 
        k++;
    }

    while(j < n){
        C[k] = B[j]; 
        j++; 
        k++;
    }
}

// Recursive function to perform merge sort on array A and store the result in B.
void mergeSort(vector<int>& A, vector<int>& B, int left, int right){
    if(right - left <= 1){
        return; // Base case: A has one or zero elements, so it's already sorted.
    }

    int mid = left + ((right - left) / 2);

    // Create subarrays l and r to divide A into two halves.
    vector<int> l(A.begin() + left, A.begin() + mid);
    vector<int> r(A.begin() + mid, A.begin() + right);

    // Recursively sort the subarrays.
    mergeSort(A, l, left, mid);
    mergeSort(A, r, mid, right);

    // Merge the sorted subarrays l and r into B.
    merge(l, r, B);
}

int main() {
    cout << "Merge Sort" << endl << endl;
    int size;
    cout << "Enter size of array : ";
    cin >> size;

    vector<int> arr(size);
    vector<int> C(size);

    // Input elements of the array.
    for (int i = 0; i < size; i++) {
        cout << "Enter element at index position " << i << " : ";
        cin >> arr[i];
    }

    cout << "Array before Merge Sort" << endl;

    // Display the original array.
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }

    cout << endl;

    // Perform merge sort on the input array and store the sorted result in C.
    mergeSort(arr, C, 0, size);

    cout << "Array after Merge Sort" << endl;

    // Display the sorted array.
    for (int i = 0; i < size; i++) {
        cout << C[i] << "\t";
    }

    cout << endl;

    return 0;
}
