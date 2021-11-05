#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

class Edges{
    public:
    int src, dest, weight;
};

bool cmp(Edges &a, Edges &b){
    return a.weight < b.weight;
}

//time: O(v)
int findParent(int v, int *parent){
    if(parent[v] == v)
         return v;
    return findParent(parent[v], parent);
}

lli build(Edges *road, int n, int m, lli cost, int *parent){
   //krushkal's algo
    lli totalWeight = 0;
    
    for(int i=0; i<m; i++){
        Edges currEdge = road[i];
        
        //check if edge cn be added in mst
        int srcParent = findParent(currEdge.src, parent);
        int destParent = findParent(currEdge.dest, parent);
        
        if(srcParent != destParent && (lli)currEdge.weight < cost){
            totalWeight += (lli)currEdge.weight;
            parent[srcParent] = destParent;
        }
    }
    
    int num_airport = 0;
    
    for(int i=1; i<=n; i++){
        if(parent[i] == i)
            num_airport++;
    }
   
    totalWeight += (lli)num_airport * cost;// cout <<totalWeight<<"wt"<<endl;
    return totalWeight;
}

lli minimum_cost(Edges *road, int n, int m, lli cost){
    sort(road, road+m, cmp); // according to weight
    
    int *parent = new int[n+1];
    for(int i=0; i<=n; i++){
        parent[i] = i;
    }
    
    lli construction_cost = build(road, n, m, cost, parent);
    
    //free space
    delete[] parent;
    
    return construction_cost;
}


//time :O(mlogm + m*n)
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n, m; lli cost; // number of locations, number of possible roads and cost of airport respectively
        cin >> n >> m >> cost;
        
        Edges *road = new Edges[m];
        
        for(int i=0; i<m; i++){
            int x, y, c;
            cin >> x >> y >> c; // X and Y are two locations, and C is the cost of building a road between X and Y
            road[i].src = x;
            road[i].dest = y;
            road[i].weight = c;
        }
        
        cout << minimum_cost(road, n, m, cost) << endl;
        //free space
    }
    return 0;
}