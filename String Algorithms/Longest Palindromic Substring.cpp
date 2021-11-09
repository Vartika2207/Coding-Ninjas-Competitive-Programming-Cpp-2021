#include<bits/stdc++.h>
using namespace std;

//time :O(n)
int LongestPalindromicSubstring(string s){
    int maxLen = 0;
    int n = s.size();
    for(int i=0; i<n; i++){
        int left, right;
        
        //odd length
        left = i; right = i;
        while(left >= 0 && right < n && s[left] == s[right]){
            maxLen = max(maxLen, right - left + 1);
            left --;
            right ++;
        }
        
        //even length
        left = i; right = i + 1;
        while(left >= 0 && right < n && s[left] == s[right]){
            maxLen = max(maxLen, right - left + 1);
            left --;
            right ++;
        }
    }
    return maxLen;
}

int main(){
    
    int t;
    t = 1;
    while(t--){
        string s;
        cin >> s;
        cout << LongestPalindromicSubstring(s) << endl;
    }
    return 0;
}