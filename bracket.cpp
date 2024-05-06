#include "bits/stdc++.h"

using namespace std;

int main() {
    string s;
    getline(cin, s);
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[') {
            st.push(s[i]);
        } else if(s[i] == ')' || s[i] == ']') {
            if (st.empty()) {
                cout << "NO" << endl;
                return 0;
            }
            if (s[i] == ')' && st.top() == '(') {
                st.pop();
            } else if (s[i] == ']' && st.top() == '[') {
                st.pop();
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << (st.empty() ? "YES" : "NO") << endl;
    return 0;
}