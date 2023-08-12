#include<iostream>
#include<unordered_map>
#include"../../boilerplate/isvalid.hpp"

void dfa(string str){

    unordered_map<string, string> state;
    unordered_map<string, string> stt;
    state = {
        {"0a", "1"}, {"0b", "0"},
        {"1a", "1"}, {"1b", "2"},
        {"2a", "3"}, {"2b", "0"},
        {"3a", "1"}, {"3b", "2"}
    };

    string curr_state = "0";

    for(const auto& x: str){
        curr_state = state[string(curr_state+x)];
    }
}

int main(){
    string inp = "aababaaaba";
   dfa(inp);
}
