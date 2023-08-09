#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

string dfa(const string& str){
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

bool isvalid(const string& inp){
    return all_of(inp.begin(), inp.end(), [](char c){
        return c == 'a' || c == 'b';
    });
}

int main(){

    string input_s;

    do{
        cout << "Enter a string over \u03A3 = {a,b}:";
        cin >> input_s;

        if(!isvalid(input_s)){
            cout << "Please enter a valid Input !!";
        }

        cout << endl;
    }while(!isvalid(input_s));

    cout << endl;

    string ans = dfa(input_s);

    if(ans == "3"){
        cout << input_s << " is a valid string with substring aba." << endl;
    }

    else{
        cout << input_s << " is not a valid string." << endl;
    }

    return 0;
    
}