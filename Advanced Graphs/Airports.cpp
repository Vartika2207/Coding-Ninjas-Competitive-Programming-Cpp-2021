/*************
AIRPORTS

The government of a certain developing nation wants to improve transportation in one of its most inaccessible areas, in an attempt to attract investment. The region consists of several important locations that must have access to an airport.
Of course, one option is to build an airport in each of these places, but it may turn out to be cheaper to build fewer airports and have roads link them to all of the other locations. Since these are long distance roads connecting major locations in the country (e.g. cities, large villages, industrial areas), all roads are two-way. Also, there may be more than one direct road possible between two areas. This is because there may be several ways to link two areas (e.g. one road tunnels through a mountain while the other goes around it etc.) with possibly differing costs.
A location is considered to have access to an airport either if it contains an airport or if it is possible to travel by road to another location from there that has an airport. You are given the cost of building an airport and a list of possible roads between pairs of locations and their corresponding costs. The government now needs your help to decide on the cheapest way of ensuring that every location has access to an airport. The aim is to make airport access as easy as possible, and with minimum cost.
Input Format:
The first line of input contains the integer T (the number of test cases), each test case follow as.
Line1: Three space-separated integers N, M and cost number of locations, number of possible roads and cost of airport respectively
The following M lines each contain three integers X, Y and C, separated by white space. X and Y are two locations, and C is the cost of building a road between X and Y .
Output Format:
For each test case print the cost in a newline.
Constraints:
1 <= T <= 20
1 <= N, M <= 10^5
1 <= cost <= 10^9
1 <= weight(of each road) <= 10^9
Sample Input
2
4 4 100
1 2 10
4 3 12
4 1 41
2 3 23
5 3 1000
1 2 20
4 5 40
3 2 30
Sample Output
145
2090
****************/

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
