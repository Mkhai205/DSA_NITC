#include "bits/stdc++.h"

using namespace std;

int main() {
    int n, M;
    cin >> n >> M;
    /**
     * @brief A vector that stores the weight of each item.
     *
     * This vector is used to store the weight of each item in the bag.
     * The weight of an item determines its contribution to the total weight of the bag.
     * The size of this vector should be equal to the number of items in the bag.
     */
    vector<int> weight(n+1), value(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weight[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    cout << dp[n][M] << endl;
    return 0;
}