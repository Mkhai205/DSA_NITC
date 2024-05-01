#include <bits/stdc++.h>

using namespace std;

bool palindrome(string s){
	string rev_s = s;
	reverse(rev_s.begin(), rev_s.end());
	
	if(s == rev_s) return true;
	return false;
}

int main(){
	string s; cin >> s;
	if(palindrome(s)) cout << "True\n";
	else cout << "False\n";
	return 0;
}
