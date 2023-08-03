#include<iostream>
using namespace std;

bool b_search(int A[], int n, int k){

    int flag = 0; 
    for(int i=0; i<n; i++){
        if(k == A[i]){
            flag = 1;
            
        }
    }
    
    if(flag == 1){
        return true;
    }

    return false;

}

int main(){
    int arr[5] = {1,2,3,4,5};
    int k  = 7;

    bool ans = b_search(arr, 5, 7);

    if(ans == true){
        cout<<k<<" is in the array.";
    }

    else{
        cout<<k<<" is not in the array.";
    }
}