#include <iostream>
#include <unordered_map>
#include "../../boilerplate/isvalid.hpp"

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
    unordered_map<char, int> transition;
    int curr_state;
    int substring_len;

public:
    DFA(const string& sub) {
        substring_len = sub.length();
        curr_state = 0;
        for (int i = 0; i < substring_len; i++) {
            transition[sub[i]] = i + 1;
        }
    }

    bool accepts(const string& inp) {
        for (const auto& x: inp){
            if(transition.find(x) == transition.end()){
                return false;
            }

            else{
                curr_state = transition[x];

                if(curr_state == substring_len){
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    string input_s;
    unordered_set<char> valid = {'a', 'b'};

    do{
        cout << "Enter a string over \u03A3 = {a,b}:";
        cin >> input_s;

        if(!isvalid(input_s, valid)){
            cout << "Please enter a string with only a,b!!" << endl << endl;
        }
    }while(!isvalid(input_s, valid));

    cout << endl;

}
