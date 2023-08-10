#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include"../../../Boilerplate/isValid.hpp"
using namespace std;

string dfa(string str){

    unordered_map <string, string> state = {
        {"0a", "1"} , {"0b", "0"},
        {"1a", "1"} , {"1b", "2"},
        {"2a", "1"} , {"2b", "3"},
        {"3a", "4"} , {"3b", "0"},
        {"4a", "4"} , {"4b", "4"}
    };

    string current_state = "0";

    for(const auto& x: str){
        current_state = state[string(current_state+x)];
    }

    return current_state;
}

int main(){


    string input_s;
    unordered_set <char> valid= {'a', 'b'};

    do{
        cout << "Enter a string over \u03A3 = {a,b}:";
        cin >> input_s;

        if(!isvalid(input_s, valid)){
            cout << "Please enter a string with only a,b!!" << endl << endl;
        }
    }while(!isvalid(input_s, valid));

    cout << endl;

    string ans = dfa(input_s);

    if(ans == "4"){
        cout << input_s << " is a valid string with substring abba." << endl;
    }

    else{
        cout << input_s << " does not have abba as substring." << endl;
    }

    return 0;
}