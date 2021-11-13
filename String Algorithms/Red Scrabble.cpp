/*************
Red Scrabble

Raymond “Red” Reddington is an international criminal hunted by the police forces of many countries. Recently, a joint Task Force, with the sole purpose of capturing Reddington, is launched, led by Agent Donald Ressler.
Red has managed to elude all the forces because he is always one step ahead. Before Ressler can catch him, Red manages to capture Ressler for interrogation.
Red is a huge fan of the game scrabble, and has created many modified versions of the game. He will let Ressler go, if he is able to solve one such version of the game.
The premise is quite simple. Ressler is given a string S which contains only digits. He needs to count the number of substrings of S, which are palindromes. There are some additional rules to be followed. Red explains them as follows -
Ressler needs to count the number of substrings of S, which are palindromes without leading zeros and can be divided by 3 without a remainder.
A string is a palindrome without leading zeros if it reads the same backward as forward and doesn't start with the symbol '0'.
Ressler should consider string "0" as a palindrome without leading zeros.
You need to help Agent Ressler.
Input Format:
The first and only line of input contains string S.
Constraints:
1 <= |S| <= 10^5
0 <= S[i] <= 9
Output Format:
Print the answer obtained.
Sample Input 1:
10686
Sample Output 1:
3
Explanation:
The three palindromic substrings are: 0, 6, 6.
**************/
#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000000;

int t[3][N];

int n;
 
int get(int r, int pos) {
    int res = 0;
 
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        res += t[pos][r];
    }
    return res;
}
 
void add(int r, int pos) {
    for (; r < n; r |= r + 1) {
        t[pos][r]++;
    }
}
 
int get(int l, int r, int pos) {
    return get(r, pos) - get(l - 1, pos);
}

ll ha1[N + 1], ha2[N + 1];
ll p[N + 1];

ll has(int l, int r, ll * ha)
{
    if (l > r)
        return 0;
    return ha[r + 1] - ha[l] * p[r - l + 1];
}

int d1[N], d2[N];

int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    ha1[0] = ha2[0] = 0;
    p[0] = 1;
    n = s.length();
    for (int i = 0; i < n; ++i)
    {
        ha1[i + 1] = 11 * ha1[i] + s[i] - '0' + 1;
        ha2[i + 1] = 11 * ha2[i] + rev_s[i] - '0' + 1;
        p[i + 1] = 11 * p[i];
    }
    
    for (int i = 0; i < n; ++i)
    {
        int l = 0, r = min(n - i - 1, i);
        while(l < r)
        {
            int m = (l + r + 1) >> 1;
            if (has(i, i + m, ha1) == has(n - 1 - i, n - 1 - i + m, ha2))
                l = m;
            else
                r = m - 1;
        }
        d1[i] = l;
        l = 0, r = min(i + 1, n - 1 - i);
        while(l < r)
        {
            int m = (l + r + 1) >> 1;
            if (has(i + 1, i + m, ha1) == has(n - 1 - i, n - 2 - i + m, ha2))
                l = m;
            else
                r = m - 1;
        }
        d2[i] = l;
    }
    
    long long ans = 0;
 
    int k = 0;
 
    for (int i = 0; i < n; ++i) {
        k = (k + (s[i] - '0')) % 3;
 
        add(i + d1[i], (k + s[i] - '0') % 3);
        if (s[i] == '0') {
            ans += 1;
        } else {
            ans += get(i, n - 1, k);
        }
        
    }
    
    memset(t, 0, sizeof(t));
    k = 0;
    for (int i = 0; i < n; ++i) {
        k = (k + (s[i] - '0')) % 3;
 
        if (s[i] != '0') {
            ans += get(i, n - 1, k);
        }
        add(i + d2[i], k);
    }
    cout << ans << endl;
    
    
    return 0;
}

// int countPSS(string s){
//     int count = 0;
//     int n = s.size();
    
//     for(int i=0; i<n; i++){
//         int left, right;
        
//         //odd length
//         left = i;
//         right = i;
//         while(left >= 0 && right < n && s[left] == s[right]){
//             int num = stoi(s.substr(left, right - left + 1));
//             if(left == right && s[left] == 0){
//                 count++;
//             }
//             else if(num % 3 == 0){
//                 count++;
//             }
//             right++;
//             left--;
//         }
        
//         //even length
//         left = i;
//         right = i + 1;
//         while(left >= 0 && right < n && s[left] == s[right]){
//             int num = stoi(s.substr(left, right - left + 1));
//             if(left == right && s[left] == 0){
//                 count++;
//             }
//             else if(num % 3 == 0){
//                 count++;
//             }
//             right++;
//             left--;
//         }
//     }
// }

// int main(){
    
//     int t;
//     t = 1;
//     while(t--){
//         string s;
//         cin >> s;
//         cout << countPSS(s) << endl;
//     }
//     return 0;
// }

