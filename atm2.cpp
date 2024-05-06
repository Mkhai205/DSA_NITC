#include "bits/stdc++.h"

using namespace std;

const int INF =  1e9;

vector<int> minNotes(vector<int> arr, int T){
    int n = arr.size();
    vector<pair<int, vector<int>>> dp(T+1, {INF, {}});
    dp[0].first = 0;

    for(int i=0; i < n; i++){
        for(int j=T; j >= arr[i]; j--){
            if(dp[j-arr[i]].first + 1 < dp[j].first){
                dp[j].first = dp[j-arr[i]].first + 1;
                dp[j].second = dp[j-arr[i]].second;
                dp[j].second.push_back(arr[i]);
            }
        }
    }

    if(dp[T].first == INF) return {-1};
    else return dp[T].second;
}

int main(){
    int n, T; cin >> n >> T;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    vector<int> ans = minNotes(arr, T);
    cout << "Minimum number of notes: " << ans.size() << endl;
    for(int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
