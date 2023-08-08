#include<iostream>
#include "../Boilerplate/swap.hpp"

void selection_sort(int A[], int n){
    for(int i=0; i<n; i++){
        int key = i;
        for(int j=i+1; j<n; j++){
            if(A[j] < A[key]){
                key = j;
            }
        }

        if(key != i){
            swap(A[i], A[key]);
        }
    }
}

void selection_sort_rec(int A[], int start, int n){
    
    int key = start;
    int j = start+1;

    if(start >= n-1){
        return;
    }

    while(j < n){
        if(A[j] < A[key]){
            key = j;
        }
        j++;
    }

    if(key != start){
        swap(A[key], A[start]);
    }

    return selection_sort_rec(A, start+1, n);

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
              << "(1) to use Selection Sort Iteratively" << std::endl
              << "(2) to use Selection Sort Recursively" << std::endl;

    int choose;
    std::cin >> choose;

    if (choose == 1) {
        selection_sort(arr, size);
    } else if (choose == 2) {
        selection_sort_rec(arr, 0, size);
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