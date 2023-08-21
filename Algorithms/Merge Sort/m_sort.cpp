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

void m_sort(int A[], int left, int right, int B[]) {
    if (right - left <= 1) {
        return;
    }

    int mid = left + ((right - left) / 2);
    int* l = new int[mid - left];
    int* r = new int[right - mid];

    m_sort(A, left, mid, l);
    m_sort(A, mid, right, r);

    merge(l, mid - left, r, right - mid, B);

    delete[] l;
    delete[] r;
}

int main(){
    int size;
    cout << "Enter size of array : ";
    cin >> size;

    int* arr = new int(size);
    int* C = new int[size];

    for(int i=0; i<size; i++){
        cout << "Enter element at index position " << i << " : ";
        cin >> arr[i];
    }

    cout << "Array before Merge Sort" << endl;

    for(int i=0; i<size; i++){
        cout << arr[i] << "\t";
    }

    cout << endl;

    m_sort(arr, 0, size, C);

    delete[] arr;
    delete[] C;
    
}