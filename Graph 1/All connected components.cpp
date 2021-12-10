/*******************
Code : All connected components

Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 1 to V.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
First line of input will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
For each test case and each connected components print the connected components in sorted order in new line.
Order of connected components doesn't matter (print as you wish).
Constraints :
2 <= V <= 10000
1 <= E <= 10000
Sample Input 1:
1
4 2
2 1
4 3
Sample Output 1:
1 2 
4 3 

*****************/

#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int> adj[], int currNode, bool *visited, vector<int> *path){
    path->push_back(currNode);
    visited[currNode] = true;
    for(auto i: adj[currNode]){
        if(!visited[i]){
             DFS(adj, i, visited, path);
        }
    }
}

vector<int> *BFS(vector<int> adj[], int s, bool *visited){
    vector<int> *smallOutput = new vector<int>();
    queue<int>pv;
    pv.push(s);
    while(!pv.empty()){
        int front=pv.front();
        pv.pop();
        visited[front]=true;
        smallOutput->push_back(front);
        for(auto i: adj[front]){
            // if(i==front) continue; //self loop
            if(!visited[i]){
                pv.push(i);
                visited[i]=true;
            }
        }
    }
    return smallOutput;
}


int main(){
    
    int t;
    cin >> t;
    while(t--){
        int v, e;
        cin >> v >> e;
        vector<int> adj[v+1];
        for(int i=0; i<e; i++){
            int f, l;
            cin >> f >> l;
            adj[f].push_back(l);
            adj[l].push_back(f);
        }
        bool *visited = new bool[v+1]();
        for(int i=1; i<=v; i++){
            if(!visited[i]){
                // vector<int> *path = BFS(adj, i, visited);
                // sort(path->begin(), path->end());
                // for(int i=0 ;i<path->size(); i++){
                //     cout << path->at(i) << " ";
                // 
                //dfs
                vector<int> *path = new vector<int>();
                DFS(adj, i, visited, path);
                sort(path->begin(), path->end());
                for(int i=0 ;i<path->size(); i++){
                    cout << path->at(i) << " ";
                     
            
            
            }
                delete path;
                cout << endl;
            }
        }
        
    }
    return 0;
}
