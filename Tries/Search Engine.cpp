/******************
Search Engine

Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.
Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.
Input Format:
First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. 
Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.
Next q lines follow, each line having a string t, which needs to be completed.
Constraints:
1 ≤ n, weight, len(s), len(t) ≤ 10^6
1 ≤ q ≤ 10^5
Total length of all strings in database entries ≤ 10^6
Total length of all query strings ≤ 10^6
Output Format:
Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.
Sample Input 1:
2 1
potential 10
potent 8
pot
Sample Output 1:
10
******************/
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
