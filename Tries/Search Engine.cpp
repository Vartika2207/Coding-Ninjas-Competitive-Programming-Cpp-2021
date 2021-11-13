#include<bits/stdc++.h>
using namespace std;

struct trieNode{
    trieNode** children;
    int weight;
    
    //contructure
    trieNode(){
        children = new trieNode*[26];
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        weight = -1;
    }
};

void insertIntoTrie(string s, int weight, trieNode* root){
    if(s.empty()){
        return;
    }
    
    trieNode* child;
    int index = s[0] - 'a';
    
    //if starting node of s already exist
    if(root->children[index]){
        child = root->children[index];
    }
    //creating new node and inserting in root
    else{
        child = new trieNode();
        root->children[index] = child;
    }
    
    if(root->weight < weight){
        root->weight = weight;
    }
    //recursion will insert rest remaining part of string
    insertIntoTrie(s.substr(1), weight, child);
}

int searchBestInTrie(string s, trieNode* root){
    
    int maxWeight = -1;
    trieNode* curr = root;
    for(int i=0; i<s.size(); i++){
        int index = s[i] - 'a';
        trieNode* child = curr->children[index];
        if(child){
            curr = child;
            maxWeight = child->weight;
        }
        //no such prefix found
        else{
            return -1;
        }
    }
    return maxWeight;
}

int main(){
    int t;
    t = 1;
    while(t--){
        int n, q;
        cin >> n >> q;
        trieNode* root = new trieNode();
        for(int i=0; i<n; i++){
            string s; cin >> s;
            int weight;
            cin >> weight;
            insertIntoTrie(s, weight, root);
        }
          
        //queries
        while(q--){
            string t;
            cin >> t;
            cout << searchBestInTrie(t, root) << endl;
        }
    }
    return 0;
}