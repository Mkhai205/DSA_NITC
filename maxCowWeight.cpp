#include <bits/stdc++.h>
using namespace std;

int max_weight = INT16_MIN;
vector<int> arr_cows;
int cow_s, C;

void init() {
    cin >> cow_s >> C;
    arr_cows.resize(cow_s);
    for (int i = 0; i < cow_s; i++) {
        cin >> arr_cows[i];
    }
}

void generateCombination(int start, int k, int weight) {
    if (k == 0) {
        if (weight > max_weight && weight <= C) {
            max_weight = weight;
        }
        return;
    }
    for (int i = start; i < cow_s; i++) {
        generateCombination(i + 1, k - 1, weight + arr_cows[i]);
    }
}

void solve() {
    for (int i = 1; i <= cow_s; i++) {
        generateCombination(0, i, 0);
    }
    cout << max_weight << endl;
}

int main() {
    init();
    generateCombination(0, 1, 0);
    solve();
    return 0;
}
