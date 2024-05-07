#include <iostream>
#include <vector>

using namespace std;

const int max_n = 1e5 + 1;

int n;
vector<vector<int>> adj(max_n);
bool visited[max_n];

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    return 0;
}