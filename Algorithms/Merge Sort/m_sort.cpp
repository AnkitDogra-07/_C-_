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