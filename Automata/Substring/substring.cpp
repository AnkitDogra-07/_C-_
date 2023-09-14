#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "../../boilerplate/isvalid.hpp"
using namespace std;

class DFA {
private:
    vector<vector<int>> transition;
    int curr_state = 0;
    int substring_len;
    
public:
    DFA(const string& sub) {
        int ct_a = 0;
        int ct_b = 0;
        substring_len = sub.length();

        transition.assign(substring_len + 2, vector<int>(2, 0));

        for (int i = 0; i <= substring_len; i++) {
            if (i < substring_len) {
                transition[i][sub[i] - 'a'] = i + 1;
                if(i == 1){
                    
                }
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

    return 0;
}
