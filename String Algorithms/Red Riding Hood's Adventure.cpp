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