/*******
Code : BFS Traversal

Given an undirected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note :
1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
BFS Traversal (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*******/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void printDFS(int **edgePath, int v, int sv, bool *visited){
    cout<<sv<<" ";
    visited[sv]=true;
    for(int i=0;i<v;i++){
        if(sv==i) continue; //self loop
        if(edgePath[sv][i]==1){
            if(visited[i]==true) continue; // vertices is already visited
            printDFS(edgePath,v,i,visited);
        }   
    }
}

void DFS(int **edgePath, int v){
    //to chheck which vertices are visited
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;  //none vertices are visited
    }
    for(int i=0;i<v;i++){
     if(!visited[i])
      printDFS(edgePath, v,i,visited);
    }
    delete[] visited;
}



void printBFS(int **edgePath, int v, int sv, bool *visited){
    
    queue<int>pv; // pening vertices
    pv.push(sv);
    visited[sv]=true;
    while(!pv.empty()){
        int front=pv.front();
        cout<<front<<" ";
        pv.pop();
        
        for(int i=0;i<v;i++){
            if(i==front) continue; //self loop
            if(edgePath[front][i]==1){
                if(visited[i]==true) continue;//already visited before
                pv.push(i);  
                visited[i]=true;
            }
        }

    }   
}

void BFS(int **edgePath, int v){
    //to check which vertices are visited
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;  //none vertices are visited
    }
    for(int i=0;i<v;i++){
     if(!visited[i])
      printBFS(edgePath, v,i,visited);
    }
    delete[] visited;
}
int main() {
    int v,e;
    cin>>v >>e;
   
    int **edges= new int*[v];    
    for(int i=0;i<v;i++) {
        edges[i]=new int[v];
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        }
    }   
    
    for(int i=0;i<e;i++){
        int s,f;
        cin>>f>>s;
        edges[f][s]=1; //path exist from f to s
        edges[s][f]=1; //path exist from s to f
    }    
    //printing the vertices
    BFS(edges,v); 
    //deleting memory
    for(int i=0;i<v;i++){
        delete[] edges[i]; 
    }
}







// #include<bits/stdc++.h>
// using namespace std;

// void printGraph(vector<int>adj[], bool* visited){
//     queue<int> q;
//     visited[0] = true;
//     q.push(0);
    
//     while(!q.empty()){
//         int front = q.front();
//         cout << front << " ";
//         q.pop();
//         for(auto x: adj[front]){
//             if(!visited[x]){
//                 q.push(x);
//                 visited[x] = true;
//             }
//         }
//     }
//     return;
// }


// int main(){
    
//     int v, e; //vertices from 1 to v-1, e is edges
//     cin >> v >> e;
    
//     vector<int>adj[v];
//     for(int i=0; i<e; i++){
//         int s, e;
//         cin >> s >> e;
//         adj[s].push_back(e);
//         adj[e].push_back(s);
//     }
    
//     bool *visited = new bool[v]();
//     printGraph(adj, visited);
    
//     //free space
//     delete[] visited;
//     return 0;
// }
