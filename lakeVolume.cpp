#include "bits/stdc++.h"

using namespace std;

int n, m, max_volume = 0, current_volume = 0;;
int lakeVolumeArray[1005][1005];
bool visited[1005][1005];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {
    current_volume += lakeVolumeArray[x][y];
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int u = x + dx[i], v = y + dy[i];
        if (u < 1 || u > n || v < 1 || v > m) continue;
        if (lakeVolumeArray[u][v] != 0 && !visited[u][v]) dfs(u, v);
    }
}

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> lakeVolumeArray[i][j];
}

void solve() {
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (lakeVolumeArray[i][j] != 0 && !visited[i][j]) {
                current_volume = 0;
                dfs(i, j);
                max_volume = max(max_volume, current_volume);
            }
    cout << max_volume << endl;
}

int main() {
    input();
    solve();
    return 0;
}

