#include "bits/stdc++.h"

using namespace std;

string longestCommonPrefix(vector<string> strs) {
    if (strs.size() == 0) return "";
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        string s = strs[i];
        int j = 0;
        while (j < prefix.size() && j < s.size() && prefix[j] == s[j]) {
            j++;
        }
        prefix = prefix.substr(0, j);
    }
    return prefix;
}

string lcp_two_string(string s1, string s2) {
    int j = 0;
    while (j < s1.size() && j < s2.size() && s1[j] == s2[j]) {
        j++;
    }
    return s1.substr(0, j);
}

string longestCommonPrefix2(vector<string> strs, int left, int right) {
    if(left == right) return strs[left];
    int mid = (left + right) / 2;
    string lcpLeft = longestCommonPrefix2(strs, left, mid);
    string lcpRight = longestCommonPrefix2(strs, mid + 1, right);
    return lcp_two_string(lcpLeft, lcpRight);
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs) << endl;
    cout << longestCommonPrefix2(strs, 0, strs.size() - 1) << endl;
    return 0;
}

