#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m ; cin >> n >> m;
    int arr[n][n];
    unordered_set<string> se;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> arr[i][j];
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            string s = to_string(arr[i][j]) + to_string(arr[i+1][j]) + to_string(arr[i][j+1]) + to_string(arr[i+1][j+1]);
            se.insert(s);
        }
    }
    cout << se.size() << endl;
    // for(auto it : se){
    //     cout << it << endl;
    // }
    return 0;
}