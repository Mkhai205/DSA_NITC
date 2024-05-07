#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, a[N][N], h_max, h_min;
bool visited[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool bfs(int delta) {
    for (int L = h_min; L <= h_max - delta; ++L) {
        int R = L + delta;
        if (a[1][1] < L || a[1][1] > R) continue;
        memset(visited, false, sizeof(visited));
        visited[1][1] = true;
        queue<pair<int, int>> st;
        st.push({1, 1});
        while (!st.empty()) {
            int i = st.front().first, j = st.front().second;
            st.pop();
            if (i == n && j == n) return true;
            for (int k = 0; k < 4; ++k) {
                int u = i + dx[k], v = j + dy[k];
                if (u < 1 || u > n || v < 1 || v > n) continue;
                if (a[u][v] < L || a[u][v] > R || visited[u][v]) continue;
                visited[u][v] = true;
                st.push({u, v});
            }
        }
    }
    return false;
}

void input() {
    cin >> n;
    h_max = 0;
    h_min = 110;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            h_max = max(h_max, a[i][j]);
            h_min = min(h_min, a[i][j]);
        }
}

void solve() {
    int L = 0, R = h_max - h_min, ans = 0;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (bfs(mid))
            ans = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    cout << ans << endl;
}

int main() {
    input();
    solve();
    return 0;
}
