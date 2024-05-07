#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n; cin >> n;
    int arr[n+1];
    bool check[n+2] = {false};
    check[n+1] = true;
    for(int i=1; i<=n; i++) cin >> arr[i];
    int curr_floor = n;
    priority_queue<int> pq;
    for(int i = 1; i <= n; i++){
        pq.push(arr[i]);
        cout << "(N" << i << ") ";
        while(!pq.empty() && check[pq.top()+1]){
            cout << pq.top() << " ";
            check[pq.top()] = true;
            pq.pop();
        }
        cout << endl;
    }
    return 0;
}