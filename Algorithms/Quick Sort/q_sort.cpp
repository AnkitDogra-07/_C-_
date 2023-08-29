#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int partition(vector<int>& A, int low, int high){
    int pivot = A[high];

    int i = low - 1;

    for(int j=low; j<high; j++){
        if(A[j] <= pivot){
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i+1], A[high]);

    return (i+1);
}

void quick_sort(vector<int>& A, int left, int right){
    if(left < right){
        int p = partition(A, left, right);
        quick_sort(A, left, p-1);
        quick_sort(A, p, right);
    }
}

int main(){
    int size;

    cout << "Enter Size of Array:";
    cin >> size;

    vector<int> arr(size);

    for(int i=0; i<size; i++){
        cout << "Element at index position " << i << " : ";
        cin >> arr[i];
    }

    cout << endl;

    cout << "Array before Quick Sort" << endl;    
    for(int i=0; i<size; i++){
        cout << arr[i] << "\t";
    }

    quick_sort(arr, 0, size - 1);

    cout << endl;

    cout << "Array after Quick Sort" << endl;    
    for(int i=0; i<size; i++){
        cout << arr[i] << "\t";
    }
}