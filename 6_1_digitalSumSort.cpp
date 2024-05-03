#include <bits/stdc++.h>

using namespace std;

int sum(int x){
    int s = 0;
    while(x){
        s += x%10;
        x /= 10;
    }
    return s;
}

bool cmp(int a, int b){
    if(sum(a) == sum(b)) return a < b;
    return sum(a) < sum(b);
}

int main(){
    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;

    sort(arr, arr+n, cmp);
    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}