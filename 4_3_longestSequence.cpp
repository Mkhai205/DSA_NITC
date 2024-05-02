#include <bits/stdc++.h>

using namespace std;

int find(vector<int> a, int i, int j){
    int k = a[j] - a[i], count = 2;
    for(int x = j+1; x<a.size(); x++){
        if(a[x] - a[i] == k*count) count++;
    }
    return count;
}

int longestSequence(vector<int> a){
    int max = 0;
    for(int i=0; i<a.size(); i++){
        for(int j=i+1; j<a.size(); j++){
            int tmp = find(a, i, j);
            if(max < tmp){
                max = tmp;
            }
        }
    }
    return max;
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    cout << longestSequence(arr) << endl;
    return 0;
}