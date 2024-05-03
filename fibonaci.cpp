#include "bits/stdc++.h"

using namespace std;

int fib[100];
const int MOD = 1e9+7;

int fibonaci(int n){
    if(n <= 1) return n;
    return (fibonaci(n-1) + fibonaci(n-2))%MOD;
}

int fibonaci2(int n){
    for(int i=2; i<=n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}


int main(){
    fib[0] = 0; fib[1] = 1;
    int n; cin >> n;
    cout << fibonaci(n) << endl;
    return 0;
}