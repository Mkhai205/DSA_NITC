#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> matrix;
int n, m;

void findPaths(int i, int j, string path){
    if(i == n && j == m){
        cout << path << endl;
        return;
    }
    if(i+1 <= n && matrix[i+1][j] == 1)
        findPaths(i+1, j, path+"D");
    if(j+1 <= m && matrix[i][j+1] == 1)
        findPaths(i, j+1, path+"R");
}

int main(){
    cin >> n >> m;
    matrix.resize(n+1);
    for(int i=0; i<=n; i++){
        matrix[i].resize(m);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> matrix[i][j];
        }
    }
    findPaths(1, 1, "");
    return 0;
}

