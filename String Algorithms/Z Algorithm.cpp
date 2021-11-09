#include <bits/stdc++.h>
using namespace std;

//time: O(n)
void buildZ(int *z, string str){
    int r = 1, l = 1, i = 0;
    int n = str.size();
    
    for(int i=1; i<n; i++){
        if(i > r){
            // i doesn't lie b/w l and r
            // z for this doesn't exist
             l =i, r = i;
             while(r < n && str[r-l] == str[r]){
                 r++;
             }
             z[i] = r - l;
             r--;
        }
        else{
            int k = i - l;
            if(z[k] <= r-i){
                // it lies b/w l and r
                // z will exist previously
                z[i] = z[k];
            }
            else{
                // some part of z is already included
                // you have to start matching further
                l = i;
                while(r < n && str[r - l]  == str[r]){
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }
}

void searchString(string text, string pattern){
    string str = pattern + "$" + text;
    int n = str.size();
    int *Z = new int[n]();
    
    buildZ(Z, str);
    
    for(int i=0; i<n; i++){
        if(Z[i] == pattern.size())
           cout << i - pattern.size() - 1 << endl;
    }
    return;
}



int main() {
    string text, pattern;
    cin >> text >> pattern;
    searchString(text, pattern);
    
    return 0;
}