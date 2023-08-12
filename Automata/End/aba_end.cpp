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
    DFA(const string& inp) {
        substring_len = inp.length();
        curr_state = 0;
        for (int i = 0; i < substring_len; i++) {
            transition[inp[i]] = i + 1;
        }
    }

    bool accepts(const string& inp) {
        
    }
};

int main() {
    string inp = "aababaaaba";
    dfa(inp);

    return 0;
}
