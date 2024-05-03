#include "bits/stdc++.h"

using namespace std;

void generateCombinations(vector<int> &combination, int start, int k, int n){
      if(k == 0){
        for(int num : combination) cout << num << " ";
        cout << endl;
        return;
      }  
      for(int i=start; i<=n; i++){
        combination.push_back(i);
        generateCombinations(combination, i+1, k-1, n);
        combination.pop_back();
      }
}

int main(){
    vector<int> combination;
    generateCombinations(combination, 1, 2, 4);
    return 0;
}