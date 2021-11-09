/***********
BOTTOM

We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.
Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).
Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
Input Format:
First line of input will contain T(number of test case), each test case follows as.
First line will contain two space-separated integers N and M denoting the number of vertex and edges respectively.
Next M line will contain two space separated integers a, b denoting an edge from a to b.
Output Format:
For each test case output the bottom of the specified graph on a single line. 
Constraints:
1 <= T <= 50
1 <= N, M <= 10^5
Sample Input:
1
3 6
3 1
2 3
3 2
1 2
1 3
2 1
Sample Output:
1 2 3 
**********/

#include<bits/stdc++.h>
using namespace std;

//correct
#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int> *edges, bool *visited, int sv, stack<int> &s){
    visited[sv] = true;
    for(int i = 0; i < edges[sv].size(); i++){
        if(!visited[edges[sv][i]]){
            DFS(edges, visited, edges[sv][i], s);
        }
    }
    s.push(sv);
}

void DFS2(bool *visited, vector<int> *edges, int sv, unordered_set<int> *component){
    visited[sv] = true;
    component->insert(sv);
    for(int i = 0; i < edges[sv].size(); i++){
        if(!visited[edges[sv][i]]){
            DFS2(visited, edges, edges[sv][i], component);
        }
    }
}

unordered_set<unordered_set<int>*> *getComponents(vector<int> *edges, vector<int> *edgesT, int v){
    bool *visited = new bool[v]();
    stack<int> stk;
    unordered_set<unordered_set<int>*> *output = new unordered_set<unordered_set<int>*>();
    for(int i = 0; i < v; i++){
        if(!visited[i]){
            DFS(edges, visited, i, stk);
        }
    }
    
    bool *visited2 = new bool[v]();
    while(!stk.empty()){
        int val = stk.top();
        stk.pop();
        if(!visited2[val]){
            unordered_set<int> *component = new unordered_set<int>();
            DFS2(visited2, edgesT, val, component);
            output->insert(component);
        }
    }
    
    return output;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int v, e;
        cin >> v;
        cin >> e;
        vector<int> *edges = new vector<int>[v];
        vector<int> *edgesT = new vector<int>[v];
        while(e--){
            int x, y;
            cin >> x >> y;
            edges[x - 1].push_back(y - 1);
            edgesT[y - 1].push_back(x - 1);
        }
        unordered_set<unordered_set<int>*> *components = getComponents(edges, edgesT, v);
        unordered_set<unordered_set<int>*> :: iterator it = components->begin();
        vector<int> ans;
        while(it != components->end()){
            unordered_set<int> *component = *it;
            auto it1 = component->begin();
            int flag = 0;
            while(it1 != component->end()){
                int val = *it1;
                for(int i = 0; i < edges[val].size(); i++){
                    if((*it)->count(edges[val][i]) == 0){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1){
                    break;
                }
                it1 ++;
            }
            if(flag == 0){
                for(auto it2 = component->begin(); it2 != component->end(); it2 ++){
                   ans.push_back(*it2 + 1);
               }
            }
            it ++;
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i< ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}




/* //approach with 1 tle
typedef long long int lli;

void dfs(vector<lli>* edges, int start, unordered_set<lli> &visited, stack<lli> &finishStack) {
	visited.insert(start);
	for (int i = 0; i < edges[start].size(); i++) {
		lli adjacent = edges[start][i];
		if (visited.count(adjacent) == 0) {
			dfs(edges, adjacent, visited, finishStack);
		}
	}
	finishStack.push(start);
}

void dfs2(vector<lli>* edges, int start, unordered_set<lli>* component, unordered_set<lli> & visited) {
	visited.insert(start);
	component->insert(start);
	for (int i = 0; i < edges[start].size(); i++) {
		lli adjacent = edges[start][i];
		if (visited.count(adjacent) == 0) {
			dfs2(edges, adjacent, component, visited);
		}
	}
}

unordered_set<unordered_set<lli>*>* getSCC(vector<lli>* edges, vector<lli>* edgesT, int n) {
	unordered_set<lli> visited;
	stack<lli> finishedVertices;
	for (int i = 0; i < n; i++) {
		if (visited.count(i) == 0) {
			dfs(edges, i, visited, finishedVertices);
		}
	}
	unordered_set<unordered_set<lli>*>* output = new unordered_set<unordered_set<lli>*>();
	visited.clear();
	while (finishedVertices.size() != 0) {
		lli element = finishedVertices.top();
		finishedVertices.pop();
		if (visited.count(element) != 0) {
			continue;
		}
		unordered_set<lli>* component = new unordered_set<lli>();
		dfs2(edgesT, element, component, visited);
		output->insert(component);
	}
	return output;
}

void store_bottom_component(unordered_set<lli>* component, vector<lli>& bottomVertices){
    unordered_set<lli> :: iterator itr = component->begin();
    while(itr != component->end()){
        bottomVertices.push_back(*itr + 1);
        itr++;
    }
}

void __bottom(vector<lli>* edges, vector<lli>* edges_transpose, int n){
    
    unordered_set<unordered_set<lli>*>* components = getSCC(edges, edges_transpose, n);
    vector<lli> *bottomVertices = new vector<lli>();
    unordered_set<unordered_set<lli>*> :: iterator itr1 = components->begin();
    while(itr1 != components->end()){
        unordered_set<lli>* component = *itr1;
        unordered_set<lli> :: iterator itr2 = component->begin();
        bool notBottom = false;
        while(itr2 != component->end()){
            for (int i = 0; i < edges[*itr2].size(); ++i) {
                    if ((*itr1)->count(edges[*itr2].at(i)) == 0){
                        notBottom = true;
                        break;
                    }
                }
                if (notBottom == true){
                    break;
                }
            itr2++;
        }
        if (notBottom == false){
                itr2 = (*itr1)->begin();
                while (itr2 != (*itr1)->end()){
                    bottomVertices->push_back(*itr2 + 1);
                    itr2++;
                }
            }   
        itr1++;
        
        //free space
        delete component;
    }
    
    //print bottom vertices
    sort(bottomVertices->begin(), bottomVertices->end());
    for (auto el : *bottomVertices) {
       cout << el << " ";
    }
    cout << endl;
    
    
    //free space
    delete components, bottomVertices;
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n, m; //denoting the number of vertex and edges respectively
        cin >> n >> m;
        vector<lli>* edges = new vector<lli>[n]();
        vector<lli>* edges_transpose = new vector<lli>[n]();
        while(m--){
            int a, b; //denoting the number of vertex and edges respectively
            cin >> a >> b;
            edges[a-1].push_back(b-1);
            edges_transpose[b-1].push_back(a-1);
        }
        
        __bottom(edges, edges_transpose, n);
        
        //free space
        delete[] edges, edges_transpose;
    }
    return 0;
}
*/
