#include<bits/stdc++.h>
using namespace std;

//counting palindromic substrs, time: O(n)
int countPSS(string s){
    int count = 0;
    int n = s.size();
    for(int i=0; i<n; i++){
        //odd len
        int left = i, right = i;
        while(left >=0 && right < n && s[left] == s[right]){
            left--;
            right++;
            count++;
        }
        
        //even len
        left = i, right = i+1;
        while(left >= 0 && right < n && s[left] == s[right]){
            left --;
            right ++;
            count++;
        }
    }
    return count;
}


int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << countPSS(s) << endl;
    }
    return 0;
}