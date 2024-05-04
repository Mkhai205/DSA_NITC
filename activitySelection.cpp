#include "bits/stdc++.h"

using namespace std;


    typedef pair<pair<int, int>, int> ppiii;
    //comparator function used in sorting the list of pairs 
    //according to increasing order of the finish day.
    bool pairCompare(ppiii a, ppiii b) {
        if (a.first.second != b.first.second) {
            return a.first.second < b.first.second;
        }
        return a.second < b.second;
    }
    
    
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n){
        vector<ppiii> x;
    
        //pushing the pair of starting and finish day and their 
        //index as pair in another list.
        for (int i = 0; i < n; i++) 
        x.push_back({{start[i], end[i]}, i + 1});
    
        //sorting the list.
        sort(x.begin(), x.end(), pairCompare);
        int last = 0;
        int res = 0;
        
        for (int i = 0; i < n; i++)
        {
            //if the starting day of this activity is greater than or equal
            //to the finish day of previously selected day then 
            //we increment the counter and update last.
            if (x[i].first.first > last) 
            {
                res++;
                last = x[i].first.second;
            }
        }
        //returning the counter.
        return res;
    }

    int main(){
        int n; cin >> n;
        vector<int> start(n), end(n);
        for(int &x : start) cin >> x;
        for(int &x : end) cin >> x;

        cout << activitySelection(start, end, n) << endl;
        return 0;
    }