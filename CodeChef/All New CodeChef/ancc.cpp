#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int o, n;
	cin >> o >> n;
	if(o > n){
	    cout << "New";
	}
	
	else if(n > o){
	    cout << "Old";
	}
	
	else{
	    cout << "Same";
	}
	return 0;
}
