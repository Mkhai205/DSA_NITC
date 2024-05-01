#include <bits/stdc++.h>

using namespace std;

string standardizeString(string s){
    s = " " + s;
    string res = "";
    for(int i=1; i<s.length(); i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            if(isalpha(s[i-1])){
                res += s[i];
            }
            else res += toupper(s[i]);
        }
        else if((s[i] >= '0' && s[i] <= '9') || (s[i] == ',')){
            res += s[i];
        }
    }

    while(res.length() > 0 && res[res.length()-1] == ',') res.erase(res.length()-1, 1);
    while(res.length() > 0 && res[0] == ',') res.erase(0, 1);
    for(int i=0; i<res.length()-1; i++){
        while(res[i] == ',' && res[i+1] == ','){
            res.erase(i+1, 1);
        }
    }
    string ans = "";
    ans += res[0];
    for(int i=1; i<res.length(); i++){
        if(res[i] >= 'a' && res[i] <= 'z'){
            ans += res[i];
        }
        else if(res[i] ==','){
            res[i+1] = (char)tolower(res[i+1]);
            ans += ", ";
            ans += res[i+1];
            i++;
        }
        else{
            res[i] = (char)tolower(res[i]);
            ans += " ";
            ans += res[i];
        } 
        
    }
    ans += "?";
    return ans;
}

int main(){
    string str;
    getline(cin , str);
    cout << standardizeString(str) << endl;
    return 0;
}