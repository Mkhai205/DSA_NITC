#include "bits/stdc++.h"
using namespace std;

typedef pair<int, int> PII;

const int MAX_N = 222;
bool isCellChecked[MAX_N][MAX_N];
int minDistanceToCell[MAX_N][MAX_N];
int n, m;
PII st, en;

// Function to read input
void readInput() {
    memset(minDistanceToCell, 0x3F, sizeof(minDistanceToCell));
    cin >> n >> m >> st.first >> st.second >> en.first >> en.second;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        isCellChecked[x][y] = true;
    }
}

// BFS traversal
void bfs() {
    minDistanceToCell[st.first][st.second] = 0;
    queue<PII> q;
    q.push(st);

    while (!q.empty()) {
        PII currentNode = q.front();
        int currentCellDistance = minDistanceToCell[currentNode.first][currentNode.second];
        q.pop();

        for (int dx = -1; dx <= 1; dx += 2) {
            for (int dy = -1; dy <= 1; dy += 2) {
                PII v = currentNode;
                while (true) {
                    v.first += dx;
                    v.second += dy;
                    if (v.first < 1 || v.first > n || v.second < 1 || v.second > n) break;
                    if (isCellChecked[v.first][v.second]) break;
                    if (minDistanceToCell[v.first][v.second] > currentCellDistance + 1) {
                        minDistanceToCell[v.first][v.second] = currentCellDistance + 1;
                        q.push(v);
                    }
                }
            }
        }
    }
}

// Function to print output
void printOutput() {
    int bishopMovesResult = minDistanceToCell[en.first][en.second];
    if (bishopMovesResult > 100000)
        cout << -1 << endl;
    else
        cout << bishopMovesResult << endl;
}

int main() {
    readInput();
    bfs();
    printOutput();
    return 0;
}
