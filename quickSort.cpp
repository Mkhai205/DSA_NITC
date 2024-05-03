#include "bits/stdc++.h"

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b;
    for(int &x : a){
        cin >> x;
        if(x != -1) b.push_back(x);
    }
    sort(b.begin(), b.end());
    int idx = 0;
    for(int &x : a){
        if(x != -1){
            x = b[idx]; idx++;
        }
    }
    for(int x : a) cout << x << " ";
    return 0;
}