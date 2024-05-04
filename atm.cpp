#include "bits/stdc++.h"

using namespace std;

const int INF =  1e9;

int main(){
    int n, T; cin >> n >> T;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    vector<int> dp(T+1, INF);
    dp[0] = 0;

    for(int i=1; i <= T; i++){
        for(int j=0; j < n; j++){
            if(i >= arr[j]){
                dp[i] = min(dp[i], dp[i-arr[j]]+1);
            }
        }
    }

    if(dp[T] == INF) cout << -1 << endl;
    else cout << dp[T] << endl;
    return 0;
}