#include<iostream>
using namespace std;

void m_sort(int A[], int m, int B[], int n, int C[]){
    int i=0, j=0, k=0;

    while(k < m+n){
        if(i < n || A[i]<=B[j]){
            C[k] = A[i]; i++; k++;
        }

        else if(j < m || B[j]<=A[i]){
            C[k] = B[j]; j++; k++;
        }
    }

    cout << "Array after Merge Sort" << endl;

    for(int x=0; x < k+1; x++){
        cout << C[x] << "\t";
    }

    delete[] A;
    delete[] C;
    delete[] A;
    delete[] B;
}

int main(){
    int size;
    cout << "Enter size of array : ";
    cin >> size;

    int* arr = new int(size);
    int* C = new int(size);

    int m = size/2;
    int n = size - m;

    int* A = new int[m];
    int* B = new int[n];

    for(int i=0; i<size; i++){
        cout << "Enter element at index position " << i << " : ";
        cin >> arr[i];
    }

    cout << "Array before Merge Sort" << endl;

    for(int i=0; i<size; i++){
        cout << C[i] << "\t";
    }

    m_sort(A, m, B, n, C);
    
}