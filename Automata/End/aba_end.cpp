#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "../../boilerplate/isvalid.hpp"
using namespace std;

// void dfa(string str) {
//     unordered_map<string, string> state;
//     unordered_map<string, string> stt;
//     state = {
//         {"0a", "1"}, {"0b", "0"},
//         {"1a", "1"}, {"1b", "2"},
//         {"2a", "3"}, {"2b", "0"},
//         {"3a", "1"}, {"3b", "2"}
//     };

//     string curr_state = "0";

//     for (const auto& x : str) {
//         curr_state = state[curr_state + x];
//         stt["q" + curr_state];
//     }
// }

// class DFA {
// private:
//     unordered_map<string, int> transition;
//     int curr_state=0;
//     int substring_len;
//     string x;
//     char sec;

// public:

//     void display(){

//         for (const auto& x : transition){
//             cout << x.first << "->" << x.second << endl;
//         }

//     }
//     DFA(const string& sub) {
//         substring_len = sub.length();
//         for (int i = 0; i < substring_len; i++) {
//             string state_str = to_string(i);
//             transition[state_str + "a"] = (i < substring_len && sub[i] == 'a') ? i + 1 : 0;
//             transition[state_str + "b"] = (i < substring_len && sub[i] == 'b') ? i + 1 : 0;
//         }
//     }

//     bool accepts(const string& inp) {
//         curr_state = 0;
//         for (char ch: inp){
//             string curr = to_string(curr_state);
//             if(transition.find(string(curr+ch)) == transition.end()){
//                 curr_state = 0;
//             }

//             else{
//                 curr_state = transition[string(curr+ch)];

//                 if(curr_state == substring_len){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

class DFA {
private:
    vector<vector<int>> transition;
    int curr_state = 0;
    int substring_len;
    
public:
    DFA(const string& sub) {
        substring_len = sub.length();

        transition.assign(substring_len + 1, vector<int>(2, 0));

        for (int i = 0; i < substring_len; i++) {
            if (i < substring_len) {
                transition[i][sub[i] - 'a'] = i + 1;
            }
        }
    }

    bool accepts(const string& inp) {
        curr_state = 0;
        for (char ch : inp) {
            if (curr_state == substring_len) {
                return true;
            }
            curr_state = transition[curr_state][ch - 'a'];
        }
        return curr_state == substring_len;
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

    if(dfa.accepts(input_s) == true){
     cout << "String contains the substring '" << sub << "'." << endl;
    } 
    
    else {
        cout << "String does not contain the substring '" << sub << "'." << endl;
    }

    // dfa.display();

    return 0;
}
