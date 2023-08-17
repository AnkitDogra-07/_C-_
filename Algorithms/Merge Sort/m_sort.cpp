#include<iostream>
using namespace std;

void merge(int A[], int m, int B[], int n, int C[]){
    int i=0, j=0, k=0;

    while(i<m && j<n){
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

    while(i<n){
        C[k] = A[i];
        i++; k++;
    }

    while(j<m){
        C[k] = B[j];
        j++; k++;
    }

    cout << "Array after Merge Sort" << endl;

    for (int x = 0; x < m + n; x++) {
        cout << C[x] << "\t";
    }
}

void m_sort(int A[], int left, int right, m, n){
    int left[m];
    int right[n];
}

int main(){
    int size;
    cout << "Enter size of array : ";
    cin >> size;

    int* arr = new int(size);

    int m = size/2;
    int n = size - m;

    int* A = new int[m];
    int* B = new int[n];
    int* C = new int[size];

    for(int i=0; i<size; i++){
        cout << "Enter element at index position " << i << " : ";
        cin >> arr[i];
    }

    for(int i=0; i<m; i++){
        A[i] = arr[i];
    }

    for(int i=0; i<n; i++){
        B[i] = arr[m+i];
    }

    cout << "Array before Merge Sort" << endl;

    for(int i=0; i<size; i++){
        cout << arr[i] << "\t";
    }

    cout << endl;

    m_sort(A, 0, size-1);

    delete[] arr;
    delete[] A;
    delete[] B;
    delete[] C;
    
}