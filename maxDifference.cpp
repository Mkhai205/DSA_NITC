#include "bits/stdc++.h"

using namespace std;

int maxDifference(vector<int> arr, int left, int right){
    if(left == right){
        return 0;
    }
    int mid = (left + right) / 2;

    int leftMaxDiff = maxDifference(arr, left, mid);
    int rightMaxDiff = maxDifference(arr, mid + 1, right);
    
    int maxLeft = arr[left];
    int minRight = arr[mid + 1];
    
    for(int i = left; i <= mid; i++){
        maxLeft = min(maxLeft, arr[i]);
    }
    
    for(int i = mid + 1; i <= right; i++){
        minRight = max(minRight, arr[i]);
    }
    
    return max(leftMaxDiff, max(rightMaxDiff, minRight - maxLeft));
}

/* The function assumes that there are 
   at least two elements in array. The 
   function returns a negative value if the
   array is sorted in decreasing order and  
   returns 0 if elements are equal */
int maxDifference2(vector<int> arr, int arr_size){
     // Maximum difference found so far
     int max_diff = arr[1] - arr[0];
      
     // Minimum number visited so far 
     int min_element = arr[0];
     for(int i = 1; i < arr_size; i++) {     
       if (arr[i] - min_element > max_diff)                             
       max_diff = arr[i] - min_element;
        
       if (arr[i] < min_element)
       min_element = arr[i];                     
     }
      
     return max_diff;
}

/* The function assumes that there are 
   at least two elements in array. The 
   function returns a negative value if the
   array is sorted in decreasing order and  
   returns 0 if elements are equal */
int maxDifference3(vector<int> arr, int arr_size){     
  int max_diff = arr[1] - arr[0];
  for (int i = 0; i < arr_size; i++) {
    for (int j = i+1; j < arr_size; j++)
    {     
      if (arr[j] - arr[i] > max_diff) 
        max_diff = arr[j] - arr[i];
    } 
  }         
  return max_diff;
} 

/* The function assumes that there are 
   at least two elements in array. The 
   function returns a negative value if the
   array is sorted in decreasing order and  
   returns 0 if elements are equal */
int maxDifference4(vector<int> arr, int arr_size){
     // Maximum difference found so far
     int max_diff = arr[1] - arr[0];
      
     // Minimum number visited so far 
     int min_element = arr[0];
     for(int i = 1; i < arr_size; i++) {     
       if (arr[i] - min_element > max_diff)                             
       max_diff = arr[i] - min_element;
        
       if (arr[i] < min_element)
       min_element = arr[i];                     
     }
      
     return max_diff;
} 

int main(){
    vector<int> arr = {2, 3, 10, 6, 4, 8, 1, 4, 3, 5, 23, 12, 
    3, 12, 1, 31, 1, 34, 13, 134, 1, 3, 13, 4, 34, 1, 41, 13, 
    1, 321, 4, 13, 4, 134, 1, 34, 13, 4, 13, 41, 34, 13, 4, 134, 134};
    cout << maxDifference(arr, 0, arr.size() - 1) << endl;
    cout << maxDifference2(arr, arr.size()) << endl;
    cout << maxDifference3(arr, arr.size()) << endl;
    cout << maxDifference4(arr, arr.size()) << endl;
    return 0;
}