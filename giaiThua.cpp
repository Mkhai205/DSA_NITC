#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int giaiThua(int n){
    if(n == 1) return 1;
    return (n*giaiThua(n-1))%MOD;
}

int main(){
    int n; cin >> n;
    cout << giaiThua(n);
    return 0;
}