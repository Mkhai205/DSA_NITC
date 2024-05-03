#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int a[n][n] = {0};
	int cnt = 1, l=0, r=n-1;
	if(n & 1) a[n/2][n/2] = n*n;
	while(l<r){
		for(int i=l; i<r; i++){
			a[l][i]= cnt++;
		}
		for(int i=l; i<r; i++){
			a[i][r] = cnt++;
		}
		for(int i=r; i>l; i--){
			a[r][i] = cnt++;
		}
		for(int i=r; i>l; i--){
			a[i][l] = cnt++;
		}
		l++; r--;
	}
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << setw(3);
        }
        cout << endl;
    }
    return 0;
}