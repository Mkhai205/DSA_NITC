#include <bits/stdc++.h>

using namespace std;

int myBinarySearch(int arr[], int l, int r, int x){
    if(r >= l){
        int mid = l + (r - l)/2;

        if(arr[mid] == x) return mid;

        if(arr[mid] > x) return myBinarySearch(arr, l, mid-1, x);

        return myBinarySearch(arr, mid+1, r, x);
    }
    return -1;
}

int main(){
    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;

    int a; cin >> a; 

    if(myBinarySearch(arr, 0, n-1, a) != -1) cout << "True" << endl;
    else cout << "False" << endl;
    // cout << binary_search(arr, arr+n, a); return true/false
    return 0;
}