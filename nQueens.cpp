#include "bits/stdc++.h"

using namespace std;

int n;
vector<int> col(10); // luu cot moi quan hau dat o hang thu i
bool isSafe(int x, int y){
    for(int i=1; i<x; i++){
        if(col[i] == y || (abs(i-x) == abs(col[i]-y))){
            return false;
        }
    }
    return true;
}

bool solveNQueens(int x){
    if(x > n){
        return true;
    }
    for(int y=1; y<=n; y++){
        if(isSafe(x, y)){
            col[x] = y;
            if(solveNQueens(x+1)) return true;
        }
    }
    return false;
}

int main(){
    cin >> n;
    if(!solveNQueens(1)){
        cout << -1 << endl;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j == col[i]) cout << "Q ";
            cout << ". ";
        }
        cout << endl;
    }
    return 0;
}
