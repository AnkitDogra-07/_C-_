#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

char sub_aba(string str){
    unordered_map<pair<char, char>, char> state;
    state[make_pair('q0','a')] = 'q1';
    state[make_pair('q0','b')] = 'q0';
    state[make_pair('q1','a')] = 'q1';
    state[make_pair('q1','b')] = 'q2';
    state[make_pair('q2','a')] = 'q3';
    state[make_pair('q2','b')] = 'q0';
    state[make_pair('q3','a')] = 'q3';
    state[make_pair('q3','b')] = 'q3';

    char current_state = 'q0';
    char next_state;

    for_each(str.begin(), str.end(), [&current_state, &state](char c){
        current_state = state[make_pair(current_state, c)];

    });

    return current_state;

}

int main(){

}