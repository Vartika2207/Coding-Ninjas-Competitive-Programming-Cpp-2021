#include <bits/stdc++.h>
using namespace std;

struct trienode{

    trienode **children;
    
    bool isLeaf = false;
    trienode()
    {
        children = new trienode *[26];
        isLeaf = false;
        for (int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};

void insert(string s, trienode *root){
    if (s.length() == 0){   
        //nale it leaf node
        root->isLeaf = true;
        return;
    }
    
    trienode *child;
    int index = s[0] - 'a';
    if (root->children[index]){
        child = root->children[index];
    }
    else{
        child = new trienode();
        root->children[index] = child;
        // current = root->children[index];
    }
    insert(s.substr(1), child);
}


void helper(trienode *current, string prefix){
    bool checker = true;
    
    //if last char of string is leaf node
    if (current->isLeaf){
        cout << prefix << endl;
    }
    
    //if string is a prefix and can provide other strings
    for (int i = 0; i < 26; i++){
        trienode *temp = current;
        if (temp->children[i]){
            char suffix = (int)i + (int)'a';
            helper(current->children[i], prefix + suffix);
        }
    }
}
void printer(trienode *root, string s){
    trienode *current = root;
    for (int i = 0; i < s.length(); i++){
        int index = s[i] - 'a';
        
        if (current->children[index]){
            current = current->children[index];
        }
        else{
            cout << "No suggestions" << endl;
            insert(s, root);
            return;
        }
    }

    helper(current, s);
}
int main()
{
    int n;
    cin >> n;
    trienode *root = new trienode();
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        insert(s, root);
    }
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        printer(root, s);
    }
}
