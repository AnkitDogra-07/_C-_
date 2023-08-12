#include <iostream>
#include <unordered_map>
#include <string>
#include "../../boilerplate/isvalid.hpp"
using namespace std;

void dfa(string str) {
    unordered_map<string, string> state;
    unordered_map<string, string> stt;
    state = {
        {"0a", "1"}, {"0b", "0"},
        {"1a", "1"}, {"1b", "2"},
        {"2a", "3"}, {"2b", "0"},
        {"3a", "1"}, {"3b", "2"}
    };

    string curr_state = "0";

    for (const auto& x : str) {
        curr_state = state[curr_state + x];
        stt["q" + curr_state];
    }
}

class DFA {
private:
    unordered_map<string, int> transition;
    int curr_state=0;
    string curr = to_string(curr_state);
    int substring_len;
    string x;
    char sec;

public:

    void display(){

        for (const auto& x : transition){
            cout << x.first << "->" << x.second << endl;
        }

    }
    DFA(const string& sub) {
        substring_len = sub.length();
        curr_state = 0;
        for (int i = 0; i < substring_len; i++) {
            if(sub[i] == 'a'){
                sec = 'b';
            }

            else{
                sec = 'a';
            }

            x = to_string(i);
            transition[string(x+sub[i])] = i+1;
            transition[string(x+sec)] = i;
        }
    }

    bool accepts(const string& inp) {
        for (char ch: inp){
            if(transition.find(string(curr+ch)) == transition.end()){
                curr_state = 0;
            }

            else{
                curr_state = transition[string(curr+ch)];

                if(curr_state == substring_len-1){
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    string input_s, sub;
    unordered_set<char> valid = {'a', 'b'};

    do{
        cout << "Enter a string over \u03A3 = {a,b}:";
        cin >> input_s;

        if(!isvalid(input_s, valid)){
            cout << "Please enter a string with only a,b!!" << endl << endl;
            continue;
        }

        cout << "Enter a substring to check for:";
        cin >> sub;
    }while(!isvalid(input_s, valid));

    cout << endl;

    DFA dfa(sub);

    // if(dfa.accepts(input_s) == true){
    //  cout << "String contains the substring '" << sub << "'." << endl;
    // } 
    
    // else {
    //     cout << "String does not contain the substring '" << input_s << "'." << endl;
    // }

    dfa.display();

    return 0;
}
