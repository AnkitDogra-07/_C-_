#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& c, int l, int m, int r){
    vector<int> temp;
    int low = l;
    int high = m+1;

    while(low <= m && high <= r){
        if(c[low] <= c[high]){
            temp.push_back(c[low]);
	    low++;
        }
        else{
            temp.push_back(c[high]);
	    high++;
        }
    }

    while(low <= m){
        temp.push_back(c[low++]);
    }

    while(high <= r){
        temp.push_back(c[high++]);
    }
    for(int i=l; i<=r; i++){
        c[i] = temp[i-l];
    }
}

void mergeSort(vector<int>& arr, int l, int r){
    if(l==r)return;
    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

int main() {
    cout << "Merge Sort" << endl << endl;
    int size;
    cout << "Enter size of array : ";
    cin >> size;

    vector<int> arr(size);

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
    mergeSort(arr, 0, size-1);

    cout << "Array after Merge Sort" << endl;

    // Display the sorted array.
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }

    cout << endl;

    return 0;
}
