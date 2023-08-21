#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& A, vector<int>& B, vector<int>& C){
    int m = A.size();
    int n = B.size();
    int i=0, j=0, k=0;

    while(i < m && j < n){
        if(A[i] <= B[i]){
            C[k] = A[i]; i++;
        }

        else{
            C[k] = B[j]; j++; 
        }
        k++;
    }

    while(i < m){
        C[k] = A[i]; i++; k++;
    }

    while(j < n){
        C[k] = B[j]; j++; k++;
    }
}

void mergeSort(vector<int>& A, vector<int>& B, int left, int right){
    if(right - left <= 1){
        return;
    }

    int mid = left + ((right - left)/2);
    vector<int> l(A.begin() + left, A.begin() + mid);
    vector<int> r(A.begin() + mid, A.begin() + right);

    mergeSort(A, l, left, mid);
    mergeSort(A, r, mid, right);

    merge(l, r, B);
}


int main() {
    int size;
    cout << "Enter size of array : ";
    cin >> size;

    vector<int> arr(size);
    vector<int> C(size);

    for (int i = 0; i < size; i++) {
        cout << "Enter element at index position " << i << " : ";
        cin >> arr[i];
    }

    cout << "Array before Merge Sort" << endl;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }

    cout << endl;

    mergeSort(arr, C, 0, size);

    cout << "Array after Merge Sort" << endl;

    for (int i = 0; i < size; i++) {
        cout << C[i] << "\t";
    }

    cout << endl;

    return 0;
}
