#include "bits/stdc++.h"

using namespace std;

string encoded_string(string s) {
    stack<string> st;
    string res = "";
    for(int i=0; i<s.length(); i++){
        if(s[i] == ']'){
            string temp = "";
            while(st.top() != "["){
                temp = st.top() + temp;
                st.pop();
            }
            st.pop();
            int num = stoi(st.top());
            st.pop();
            string temp2 = "";
            for(int j=0; j<num; j++){
                temp2 += temp;
            }
            st.push(temp2);
        }
        else{
            st.push(string(1, s[i]));
        }
    }
    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }
    return res;
}

int main() {
    string s; cin >> s;
    cout << encoded_string(s) << endl;
    return 0;
}