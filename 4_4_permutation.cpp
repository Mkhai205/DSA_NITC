#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    if(n <= 4){
        cout << "NO SOLUTION\n";
        return 0;
    }
    vector<int> arr = {4, 1, 3, 5, 2};
    for(int i=6; i<=n; i++){
        if(i & 1) arr.push_back(i);
        else arr.insert(arr.begin(), i);
    }
    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}