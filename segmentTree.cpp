#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
ll n, m, k;
vector<ll> arrA;
vector<ll> arrB;
vector<ll> tree(100000000);

void buildST(ll id, ll l, ll r) {
    if(l == r){
        ll left = 0, right = n - 1;
        ll pos;
        if(arrA[l] >= arrB[n-1]) tree[id] = arrA[l] - arrB[n-1];
        else if(arrA[l] <= arrB[0]) tree[id] = arrA[0] - arrB[l];
        else {
            while(left <= right) {
                ll mid = (l + r) / 2;
                if(arrB[mid] <= arrA[l] && arrA[l] <= arrB[mid+1]) {
                    pos = mid;
                    break;
                if(arrA[l] >= arrB[mid]) left = mid + 1;
                else if(arrA[l] < arrB[mid]) right = mid - 1;
                }
            }
            tree[id] = min(abs(arrA[l] - arrB[pos]), abs(arrA[l] - arrB[pos+1]));
        }
    }
    else {
        ll mid = (l + r) / 2;
        buildST(id * 2 + 1, l, mid);
        buildST(id * 2 + 2, mid + 1, r);
        tree[id] = min(tree[id * 2 + 1], tree[id * 2 + 2]);
    }
}

ll getMin(ll l, ll r, ll ql, ll qr, ll id) {
        if(ql <= l && r <= qr) return tree[id];
        if(ql > r || qr < l) return 1e18;
        ll mid = (l + r) / 2;
        return min(getMin(l, mid, ql, qr, id * 2 + 1), getMin(mid + 1, r, ql, qr, id * 2 + 2));
    }

int main() {
    cin >> n >> m >> k;
    arrA.resize(n);
    arrB.resize(m);
    for(ll i = 0; i < n; i++) cin >> arrA[i];
    for(ll i = 0; i < m; i++) cin >> arrB[i];
    sort(arrB.begin(), arrB.end()); 
    buildST(0, 0, m - 1);
    while(k--){
        ll ql, qr;
        cin >> ql >> qr;
        cout << getMin(0, m - 1, ql - 1, qr - 1, 0) << endl;
    }
    return 0;
}
