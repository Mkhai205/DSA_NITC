#include <bits/stdc++.h>

using namespace std;

bool p[1000001];

const int MOD = 22082018;

void snt(int n){
	for(int i=2; i<=n; i++){
		p[i] = true;
	}
	p[0] = p[1] = false;
	for(int i=2; i<=sqrt(n); i++){
		if(p[i]){
			for(int j=i*i; j<=n; j+=i){
				p[j] = false;
			}
		}
	}
}

int primeSum(int n){
	snt(n);
	int sum = 0;
	for(int i=2; i<=n; i++){
		if(p[i]){
			sum = (sum+i%MOD)%MOD;
		}
	}
	return sum;
}

int main(){
	int n; cin >> n;
	cout << primeSum(n) << endl;
	return 0;
}
