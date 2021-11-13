/*********************
Red Riding Hood's Adventure

Little Red Riding Hood has to go to her grandmother’s house. Her grandmother is very sick. To reach her house, Red Riding Hood has to cross a very long dark forest. She is also carrying a basket full of food for her journey. The forest was much longer than anticipated, and Riding Hood decided to take rest. She finds a cave and lights a campfire inside it to keep herself warm for the night. But alas! The campfire attracts the Big Bad Wolf.
Luckily the Big Bad Wolf has recently turned vegetarian, and will not eat Red Riding Hood. He takes all the food that she was carrying instead, but decided to keep her as a minion. She cries a lot and begs the wolf to let her go. Big Bad Wolf used to be a problem solver in the past, and decides to let her go if and only if she is able to solve a problem for him. He gives the Red Riding Hood a long sentence “X” and a small word “W” . She has to find how many times word “W” occurs as a substring of “X” (spaces in the sentence are not to be considered). Red Riding Hood is just a kid, you have to help her solve the problem and escape the Big Bad Wolf.
Input Format :
First line of input will contain T(number of test cases). Each test case follows.
Line 1: contains the sentence X
Line 2: contains the string W
Constraints:
1 <= T <= 100
1 <= |S| ,|s| <= 10^5 
Output Format:
For each test case print the answer in a new line.
Sample Input 1:
4
axb ycz d
abc
ab  cab cabc abc
abc
aab acbaa bbaaz
aab
aaaaaa
aa
Sample Output 1:
0
4
2
5

**********************/
#include <bits/stdc++.h>
using namespace std;
void LPS(string patt, int lps[], int m) 
{
    lps[0] = 0;
    int i = 1, len = 0;
    while (i < m) 
    {
        if (patt[i] == patt[len]) 
        {
            len++; 
            lps[i] = len;
            i++; 
        }
        else
        {
            if (len != 0) 
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++; 
            }
        }
    }
    return;
}
int KMP(string text, string patt)
{
    int n = text.length();
    int m = patt.length(); 
    int lps[m];
    memset(lps, 0, sizeof lps);
    LPS(patt, lps, m);
    int i = 0, j = 0, ans = 0;
    while (i < n)
    {
        if (text[i] == patt[j]) 
        {
            i++; 
            j++;
        }
        if (j == m)
        {
            ans++; 
            j = lps[j - 1];
        }
        else if (i < n && text[i] == ' ')
            i++;
        else if (i < n && text[i] != patt[j]) 
        {
            if (j != 0) 
            {
                j = lps[j - 1]; 
            }
            else
                i++; 
        }
    }
    return ans;

}
int main()
{
    int t;
    cin >> t;
    string text, patt;
    getline(cin, text);
    while (t--)
    {
        getline(cin, text); 
        cin >> patt; 
        cout << KMP(text, patt) << endl;
        getline(cin, text); 
    }
}



// #include<bits/stdc++.h>
// using namespace std;

// void LPS(int n, int *lps, string pattern){
//     lps[0] = 0;
    
//     int i = 1, j = 0;
//     while(i < n){
//         if(pattern[i] == pattern[j]){
//             j++;
//             lps[i] = j;
//             i++;
//         }
//         else{
//             if(j != 0){
//                 j = lps[j-1];
//             }
//             else{
//                 lps[i] = 0;
//                 i++;
//             }
//         }
//     }
    
//     // for(int i=0; i<n; i++) cout<<lps[i] << " ";
    
//     return;
// }

// int RidingHood_adventure(string text, string pattern){
//     int t_len = text.size();
//     int p_len = pattern.size();
    
//     int *lps = new int[p_len]();
//     LPS(p_len, lps, pattern);
    
//     int i = 0, j = 0, ans = 0;
//     while(i < t_len){
//         if(text[i] == pattern[j]){
//             i++;
//             j++;
//         }
//         if(j == p_len){
//             ans++;
//             j = lps[j-1];
//         }
//         else if(i < t_len && text[i] == ' '){
//             i++;
//         }
//         else if(i < t_len && text[i] != pattern[j]){
//             if(j != 0){
//                 j = lps[j-1];
//             }
//             else{
//                 i++;
//             }
//         }
//     }
//     return ans;
// }


// int main(){
    
//     int t;
//     cin >> t;
//     string text, pattern;
//     while(t--){
//         getline(cin, text); //cout<<x<<endl;
//         cin >> pattern;
//         // getline(cin, w); //cout<<w<<endl; 
        
//         cout << RidingHood_adventure(text, pattern) << endl;
//         getline(cin, text);  
//     }
//     return 0;
// }
