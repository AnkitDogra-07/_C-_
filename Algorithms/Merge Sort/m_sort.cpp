#include<iostream>

void m_sort(int A[], int m, int B[], int n, int C[]){
    int i=0, j=0, k=0;

    while(k < m+n){
        if(i == n || A[i]<=B[j]){
            C[k] = A[i]; i++; k++;
        }

        else if(j == m || B[j]<=A[i]){
            C[k] = B[j]; j++; k++;
        }
    }
}