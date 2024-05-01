#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int res = 1;
    for(int i=n; i>=1; i--){
        res *= i;
        while(res%10 == 0){
            res /= 10;
        }
        res %= 10;
    }
    cout << res << endl;
    return 0;
}