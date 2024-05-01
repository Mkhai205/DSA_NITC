#include <bits/stdc++.h>

using namespace std;

bool prime[1000001];
 
void snt(int n){
    for(int i=2; i<=n; i++){
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    prime[0] = prime[1] = false;
    for(int i=2; i<=sqrt(n); i++){
        if(prime[i]){
            for(int j=i*i; j<=n; j+=i){
                prime[j] = false;
            }
        }
    }
}

int greatest_common_prime_divisor(int a, int b){
    snt(min(a, b));
    int d = 0;
    for(int i=min(a, b); i>=2; i--){
        if(prime[i] && a%i==0 && b%i==0){
            return i;
        }
    }
    return -1;
}



int main(){
    int a, b; cin >> a >> b;
    cout << greatest_common_prime_divisor(a, b);
    return 0;
}