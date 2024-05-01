#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;
    unordered_set<string> se;
	for(int i=1; i<=s.length(); i++){
		int j=0;
		while(j+i<=s.length()){
			se.insert(s.substr(j, i));
			j++;
		}
	}
    cout << se.size() << endl;
    return 0;
}