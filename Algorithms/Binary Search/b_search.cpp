#include<iostream>
using namespace std;

int b_search(int A[], int l, int r, int key){ //Iterative Binary Search...
    
    while(l <= r){
        int mid = l + (r-l)/2;

        if(key == A[mid]){
            return mid;
        }

        if(key < A[mid]){
            r = mid - 1;
        }

        else{
            l = mid + 1;
        }
    }

    return -1;

}

int b_search_rec(int A[], int l, int r, int key){ //Recurisve Binary Search...

    if(l <= r){
        int mid = l + (r-l)/2;

        if(key == A[mid]){
            return mid;
        }

        if(key < A[mid]){
            return b_search_rec(A, l, mid-1, key);
        }

        return b_search_rec(A, mid+1, r, key);
    }

    return -1;
}

int main(){
    int size;
    cout << "Enter size of array:";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter element at position " << i << ":";
        cin >> arr[i];
    }

    cout << endl;

    int ans;
    int x;
    cout << "Enter number to search:";
    cin >> x;
    cout << endl;

    cout << "Enter" << std::endl
              << "(1) to use Binary Search Iteratively" << std::endl
              << "(2) to use Binary Search Recursively" << std::endl;

    int choose;
    cin >> choose;

    if (choose == 1) {
        ans = b_search(arr, 0, size-1, x);
    } else if (choose == 2) {
        ans = b_search_rec(arr, 0, size-1, x);
    } else {
        cout << "Invalid choice. Please enter 1 or 2.\n";
    }

    if(ans != -1){
        cout << x << " is present at index position " << ans;
    }

    else{
        cout << x << " is not present in array.";
    }

    delete[] arr;

    return 0;
}