#include "bits/stdc++.h"

using namespace std;

int n, m;
char grid[1001][1001];
bool visited[1001][1001];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (is_valid(new_x, new_y) && !visited[new_x][new_y]) {
            dfs(new_x, new_y);
        }
    }
}

void input(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
}

void solve(){
    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i, j);
                rooms++;
            }
        }
    }
    cout << rooms << endl;
}

int main(){
    input();
    solve();
    return 0;
}