#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

string dfa(string str){
    unordered_map<string, char> state = {
        {"0b", '0'}, {"0a", '1'},
        {"1a", '1'}, {"1b", '2'},
        {"2a", '3'}, {"2b", '0'},
        {"3a", '3'}, {"3b", '3'}
    };

    string current_state = "0";

    for (char c : str) {
        current_state = state[string(current_state + c)];
    }

    return current_state;

}

int main(){

    string input_s;

    cout << "Enter a string over \u03A3 = {a,b}:";
    cin >> input_s;

    cout << endl;

    string ans = dfa(input_s);

    if(ans == "3"){
        cout << input_s << " is a valid string with substring aba.";
    }

    else{
        cout << input_s << " is not a valid string.";
    }

    return 0;
    
}