/***********
Code : Get Path - BFS

Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
First line of input will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space) for each test case in new line.
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
************/

#include<bits/stdc++.h>
using namespace std;

vector<int>* BFS(int **mat, int start, int end, bool *visited, int v){
    if(start == end){
        vector<int>* output = new vector<int>();
        output->push_back(start);
        return output;
    }
    
    queue<int> q;
    q.push(start);
    map<int, int>vertexPath;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        visited[front] = true;
        for(int i=0; i<v; i++){
            if(i == front) continue;
            if(mat[i][front] && !visited[i]){
                q.push(i);
                visited[i] = true;
                vertexPath[i] = front; //vertexPath max keeps a record who inserted i in q queue
                
                //end node encountered
                if(i == end){
                    vector<int> *output = new vector<int>();
                    output->push_back(end);
                    while(output->back() != start){
                        output->push_back(vertexPath[output->back()]);
                    }
                    return output;
                }
            }
        }
    }
    return NULL;
}


vector<int> *getPath(int **mat, int start, int end, int v){
    bool *visited = new bool[v]();
    vector<int>* output = BFS(mat, start, end, visited, v);
    //delete space
    delete[] visited;
    return output;
}


int main(){
    
    int t;
    cin >> t;
    while(t--){
        int v, e;
        cin >> v >> e;
        
        int **mat = new int*[v];
        for(int i=0; i<v; i++){
            mat[i] = new int[v]();
        }
        
        for(int i=0; i<e; i++){
            int s, e;
            cin >> s >> e;
            mat[s][e] = 1;
            mat[e][s] = 1;
        }
        int v1, v2;
        cin >> v1 >> v2;
        
        vector<int>*output = getPath(mat, v1, v2, v);
        if(output != NULL){
            //print path
            for(int i=0; i<output->size(); i++){
                cout << output->at(i) << " ";
            }
        }
        else
            cout << endl;
        cout << endl;
        
        //free space
        for(int i=0; i<v; i++){
            delete[] mat[i];
        }
        delete mat;
        delete output;
    }
    return 0;
}
