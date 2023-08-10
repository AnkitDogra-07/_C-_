#ifndef ISVALID_HPP
#define ISVALID_HPP

#include<algorithm>
#include<unordered_set>
using namespace std;

template <typename T>
bool isvalid(const T& str, const unordered_set<typename T::value_type>& valid_chars){
    return all_of(str.begin(), str.end(), [&](typename T::value_type c){
        return valid_chars.find(c) != valid_chars.end();
    });
}

#endif