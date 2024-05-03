#include "bits/stdc++.h"

using namespace std;

void generateBinary(int n, vector<int> &binary){
    if(n == 0){
        for(int bit : binary){
            cout << bit;
        }
        cout << endl;
    }
    else{
        binary.push_back(0);
        generateBinary(n-1, binary);
        binary.pop_back();

        binary.push_back(1);
        generateBinary(n-1, binary);
        binary.pop_back();
    }
}

int main(){
    vector<int> binary;
    int n; cin >> n;
    generateBinary(n, binary);
    return 0;
}