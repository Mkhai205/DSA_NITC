#include "bits/stdc++.h"

using namespace std;

void egyptian_representation(int a, int b){
    if(a == 0 || b ==0) return;
    if(b%a == 0){
        cout << 1 << " " << b/a;
        return;
    }
    int x = b/a + 1;
    cout << 1 << " " << x << endl;

    egyptian_representation(a*x-b, b*x);
}

int main(){
    int a, b; cin >> a >> b;
    egyptian_representation(a, b);
    return 0;
}