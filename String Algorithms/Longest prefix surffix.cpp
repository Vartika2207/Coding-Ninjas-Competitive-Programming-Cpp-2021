#include <bits/stdc++.h>
using namespace std;


//longest prefix surffix explain
//time: O(n)

void printArray(int *arr, int n){
    for(auto i=0; i<n; i++){
        cout << arr[i] << " " ;
    }
}

void getLps(string pattern){
    int len = pattern.length();
    int *lps = new int[len];
    
    lps[0] = 0;
    int i = 1, j = 0;
    while(i < len){
        if(pattern[i] == pattern[j]){
            lps[i] = j + 1;
            j++; i++;
        }
        else{
            if(j != 0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    printArray(lps, len);
}


int main() {
    string s;
    cin >> s;
    getLps(s);
}