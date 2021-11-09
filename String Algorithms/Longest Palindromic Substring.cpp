/**********
Longest Palindromic Substring

You are given a string S .You have to find the length of the longest palindromic substring of S.
Input Format:
First line of input contains the string S.
Constraints:
1 <= |S| <= 4*10^6
Output Format:
You have to print the length of longest palindromic substring
Sample Input 1:
zkpbhxkmauuamkxsyi
Sample Output 1:
10
Explanation:
In the given sample test case, the longest palindromic substring is: xkmauuamkx.
***********/



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
