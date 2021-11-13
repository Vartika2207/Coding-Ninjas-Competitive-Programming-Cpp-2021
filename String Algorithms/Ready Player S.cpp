/*****************
Ready Player S?

OASIS is a virtual reality created by the legendary James Halliday. After Halliday's death, a pre-recorded message left by him announced a game, which would grant the ownership and control of the OASIS to the first player who finds the Golden Easter Egg within it.
Shivali, an OASIS player, is obsessed with the game and finding the Easter Egg. But she has to fight the IOI clan, who wants to control OASIS for evil purposes. Both of them gather troops of different types and form a big army to fight each other.
IOI has N troops of lowercase letters forming a huge army. Shivali has an army of length M.
She will win, if the first k troops she takes from her army, can kill any of the k consecutive troops of the IOI army.
Remember a troop of type 'a' can only kill a troop of type 'a'.
You have to find how many times she can win.
Input Format:
The first line of input contains N, M and k, space separated.
Next two lines contains the string of troops of length N and M respectively in lowercase letters.
Constraints:
1 <= N, M <= 10^6
1 <= K <= M
Output Format:
Output the number of wins she is going to take at the end of the day. Print -1 if she can't win.
Sample Input 1:
3 2 1
bbb
bb
Sample Output 1:
3
********************/

#include<bits/stdc++.h>
using namespace std;

void checker(int p_len, string &pattern, vector<int> &v)
{
    int j = 0;
    for (int i = 1; i < p_len; ++i)
    {
        while (j >= 0 and pattern[j] != pattern[i])
        {
            if (j > 0)
                j = v[j - 1];
            else j = -1; 
        }
        j += 1; 
        v[i] = j;
    }
}
bool find_occurence(int t_len, int p_len, string &text, string &pattern, vector<int> &v, int &ans) 
{
    bool found = false; 
    int j = 0; 
    for (int i = 0; i < t_len; ++i)
    {
        while (j >= 0 and text[i] != pattern[j])
        {
            if (j > 0) 
                j = v[j - 1];
            else j = -1;
        }
        j += 1; 
        if (j == p_len) 
        {
            j = v[p_len - 1]; 
            ans++;
            found = true;
        }
    }
    return found; 
}
int main() 
{
    int n, m, k;
    string text, temp, pattern = "";
    cin >> n >> m >> k; 
    cin >> text >> temp;
    for (int i = 0; i < k; ++i) 
        pattern += temp[i];
    int t_len = text.size();
    int p_len = pattern.size();//k
    vector<int> v(p_len, 0);
    checker(p_len, pattern, v); 
    int ans = 0;
    bool found = find_occurence(t_len, p_len, text, pattern, v, ans); 
    if (found == false) 
        cout << -1 << endl; 
    else 
        cout << ans << endl;
}
