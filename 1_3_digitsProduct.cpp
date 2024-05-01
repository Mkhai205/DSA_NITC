#include <bits/stdc++.h>

using namespace std;

bool isprime(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return n>1;
}

string solve(int n){
    if(isprime(n)) return "-1";
    if(n == 1) return "1";
    if(n == 0) return "10";
    string ans = "";
    for(int i=9; i>=2; i--){
        while(n%i==0){
            ans = to_string(i) + ans;
            n /= i;
        }
    }
    return ans;
}

int main(){
    int n; cin >> n;
    cout << solve(n);
    return 0;
}