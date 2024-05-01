#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;

    int max_sum = arr[0];
    int cur_sum = arr[0];
    int start_idx = 0;
    int end_idx = 0;
    int cur_start_idx = 0;

    for(int i=1; i<n; i++){
        if(cur_sum < 0){
            cur_sum = arr[i];
            cur_start_idx = i;
        }
        else{
            cur_sum += arr[i];
        }

        if(cur_sum > max_sum){
            max_sum = cur_sum;
            start_idx = cur_start_idx;
            end_idx = i;
        }
    }

    cout << start_idx + 1 << " " << end_idx + 1 << " "
         << max_sum << endl;
    return 0;
}