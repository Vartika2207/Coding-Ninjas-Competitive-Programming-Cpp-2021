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