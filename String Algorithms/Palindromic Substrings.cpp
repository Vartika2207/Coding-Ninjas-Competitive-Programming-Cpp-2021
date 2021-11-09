#include<bits/stdc++.h>
using namespace std;

/*************
Palindromic Substrings

Given a string S, count and return the number of substrings of S that are a palindrome.
Single length substrings are also palindromes. You just need to print the count of palindromic substrings, not the actual substrings.
Input Format:
First line of input contains an integer T, representing the number of test cases.
Next T lines contain the string S
Constraints :
1 <= Length of S <= 2000
Output Format :
For each test case, print the count of palindrome substrings in a new line.
Sample Input 1:
1
aba
Sample Output 1:
4
Explanation:
The 4 palindrome substrings are "a", "b", "a" and "aba".
**************/

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
