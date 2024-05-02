#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;
    int row = s[0] - 'a' + 1;
    int col = s[1] - '0';
    int ans = 0;
    pair<int, int> dxy[] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
                            {1, -2}, {2, -1}, {2, 1}, {1, 2}}; 
    
    for(int i=0; i<8; i++){
        int row_t = row + dxy[i].first;
        int col_t = col + dxy[i].second;
        if(row_t >=1 && row_t <= 8 && col_t >=1 && col_t <=8) ans++;
    }
    cout << ans << endl;
    return 0;
}