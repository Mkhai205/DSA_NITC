#include <bits/stdc++.h>

using namespace std;

int n, m; 
int arr[25][25];
int cnt = 1;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool findPath(int x, int y){
    if(cnt == n*m) return true;
    cnt++;
    for(int i=0; i<4; i++){ 
        int x_t = x + dx[i];
        int y_t = y + dy[i];
        if(x_t >= 0 && x_t < n && y_t >= 0 && y_t < m && arr[x_t][y_t] == cnt){
            if(findPath(x_t, y_t)) return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    int x = -1, y = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                x = i; y = j;
            }
        }
    }
    if(x == -1){
        cout << "false\n";
        return 0;
    }
    bool check = findPath(x, y);
    if(check) cout << "true\n";
    else cout << "false\n";
    return 0;
}