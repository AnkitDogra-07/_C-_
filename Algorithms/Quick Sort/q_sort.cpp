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

void quick_sort()