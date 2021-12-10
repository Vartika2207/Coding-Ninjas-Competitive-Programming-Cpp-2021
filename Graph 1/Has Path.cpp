/*************
Code : Has Path

Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
First line will contain T(number of test cases), each test case as follow.
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false for each test case in a newline.
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
true
Sample Input 2 :
1
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
***********/

#include<bits/stdc++.h>
using namespace std;

bool hasPath(vector<int>adj[], int v1, int v2, int v){
    queue<int> q;
    bool *visited = new bool[v]();
    q.push(v1);
    visited[v1] = true;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        visited[front] = true;
        if(front == v2)
            return true;
        for(auto a: adj[front]){
            if(!visited[a])
                q.push(a);
        }
    }
    return false;
}


int main(){
    
    int t;
    cin >> t;
    while(t--){
        int e, v;
        cin >> v >> e;
        // int **mat = new int*[v];
        // for(int i=0; i<v; i++){
        //     mat[i] = new int[v]()
        // }
        vector<int>adj[v];
        for(int i=0; i<e; i++){
            int s, end;
            cin >> s >> end;
            adj[s].push_back(end);
            adj[end].push_back(s);
        }
        int v1, v2;
        cin >> v1 >> v2;
        
        bool ans = hasPath(adj, v1, v2, v);
        if(ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
