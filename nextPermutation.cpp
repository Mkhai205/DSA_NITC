#include "bits/stdc++.h"

using namespace std;

int n, a[10];
bool stop = false;

void init(){
    for(int i=1; i<=n; i++){
        a[i] = i;
    }
}

void generateNextPermutation(){
    int i = n-1;
    while(i > 0 && a[i] > a[i+1]) i--;
    if(i == 0) stop = true;
    else{
        int k = n;
        while(a[i] > a[k]) k--;
        swap(a[k], a[i]);
        reverse(a+i+1, a+n+1);
    }
}

void printPermutation(){
    for(int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void generatePermutations(){
    cin >> n;
    init();
    do{
        printPermutation();
        generateNextPermutation();
    } while(!stop);
}

int main(){
    generatePermutations();
    return 0;
}