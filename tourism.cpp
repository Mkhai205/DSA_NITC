#include "bits/stdc++.h"

using namespace std;

const int max_n = 21;
int n, current_cost, best_cost, min_cost = 1e9;
int best_path[max_n], current_path[max_n], path[max_n][max_n];
bool visited[max_n];
int cnt = 0;

void input(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> path[i][j];
            if(path[i][j] != 0){
                min_cost = min(min_cost, path[i][j]);
            }
        }
    }
    memset(visited, false, sizeof(visited));
    current_path[1] = 1;
    visited[1] = true;
    best_cost = 1e9;
}

void update_best_path(){
    for(int i=1; i<=n; i++){
        best_path[i] = current_path[i];
    }
    best_cost = current_cost + path[current_path[n]][current_path[1]];
}

/**
 * Backtracks and applies the branch and bound algorithm to find the best path.
 * 
 * This function recursively explores all possible paths starting from the current position `k`.
 * It uses the branch and bound technique to prune the search space and find the best path.
 * 
 * @param k The current position in the path.
 */
void backtrack_branch_and_bound(int k){
    cnt++;
    for(int i = 2; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            current_path[k] = i;
            current_cost += path[current_path[k-1]][current_path[k]];
            if(k == n && current_cost + path[current_path[n]][current_path[1]] < best_cost) update_best_path();
            else if (current_cost + (n-k+1)*min_cost < best_cost) {
                backtrack_branch_and_bound(k+1);
            }
            visited[i] = false;
            current_cost -= path[current_path[k-1]][current_path[k]];
        }
    }
}


void print_best_path(){
    cout << "Best path: ";
    for(int i=1; i<=n; i++){
        cout << best_path[i] << " ";
    }
    cout << best_path[1] << endl;
    cout << "Best cost: " << best_cost << endl;
}

int main(){
    input();
    backtrack_branch_and_bound(2);
    // print_best_path();
    cout << best_cost << endl;
    return 0;
}