#include "bits/stdc++.h"

using namespace std;

int main(){
    int n; cin >> n;
    int i = 1;
    while(n >= i*5){
        n -= i*5;
        i *= 2;
    }
    int res = n/i;
    if(res == 0) cout << 1 << endl;
    else if(res == 1) cout << 2 << endl;
    else if(res == 2) cout << 3 << endl;
    else if(res == 3) cout << 4 << endl;
    else cout << 5 << endl;
    return 0;
}


// int main(){
//     int n; cin >> n;
//     int i = log2(n/5+1)+1;
//     int res = (n%(int)(pow(2, i-1)*5))/i;
//     if(res == 0) cout << 1 << endl;
//     else if(res == 1) cout << 2 << endl;
//     else if(res == 2) cout << 3 << endl;
//     else if(res == 3) cout << 4 << endl;
//     else cout << 5 << endl;
//     return 0;
// }