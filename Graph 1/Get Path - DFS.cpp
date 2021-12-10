/*********
Code : Get Path - DFS

Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
First line will contain T(number of test case), each test follow as.
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space) for each test case in newline.
Constraints :
1 <= T <= 10
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
1
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
1
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*********/

#include<bits/stdc++.h>
using namespace std;

vector<int> *DFS(int **adj, int start, int end, bool *visited, int v){
    if(start == end){
        vector<int>* output = new vector<int>();
        output->push_back(end);
        return output;
    }
    visited[start] = true;
    
    for(int i=0; i<v; i++){
        if(adj[start][i] && !visited[i]){
            vector<int> *smallOutput = DFS(adj, i, end, visited, v);
            if(smallOutput != NULL){
                smallOutput->push_back(start);
                return smallOutput;
            }
        }
    }
    return NULL;
}

vector<int> *hasPathDFS(int **adj, int v1, int v2, int v){
    bool *visited = new bool[v]();
    
    vector<int> *ans = DFS(adj, v1, v2, visited, v);
    //delete visited
    delete[] visited;
    return ans;
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int v, e;
        cin >> v >> e;
        int **adj = new int*[v];
        for(int i=0; i<v; i++){
            adj[i] = new int[v]();
        }
        for(int i=0; i<e; i++){
            int start, end;
            cin >> start >> end;
            adj[start][end] = 1;
            adj[end][start] = 1;
        }
        int v1, v2;
        cin >> v1 >> v2;
        
        vector<int> *path = hasPathDFS(adj, v1, v2, v);
        if(path != NULL){
            //print path
            // cout << endl;
            for(int i=0; i<path->size(); i++)
                cout << path->at(i) << " ";
        }
        else
            cout << endl;
        cout << endl;
        //free space
        delete path;
        for(int i=0; i<v; i++)
            delete[] adj[i];
        delete[] adj;
    }
    return 0;
}
