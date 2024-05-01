#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;
    unordered_map<char, int> mp;
    for(char c : s){
        mp[c]++;
    }
    for(auto it : mp){
        if(it.second > 1){
            cout << it.first << " ";
        }
    }
    return 0;
}