#include <bits/stdc++.h>
using namespace std;

bool isMatching(string s, string p){
    int s_size = s.size();
    int p_size = p.size();
    
    for(int i=0; i<(s_size-p_size); i++){
        bool isFound = true;
        for(int j=0; j<p_size; j++){
            if(s[i+j] != p[j]){
                isFound = false;
                break;
            }
        }
        if(isFound == true){
            return true;
        }
    }
    return false;
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << isMatching(s, p) << endl;
    return 0;
}