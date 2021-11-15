#include<bits/stdc++.h>
using namespace std;

struct Points{
  double x, y;
};

struct Polygon{
    Points* points;
    
    Polygon(int n){
        points = new Points[n];//n is number of points
    }
};

int areaOfPolygon(Polygon p, int n){
    double tArea = 0;
    for(int i=1; i<n-1; i++){
        double x1 = p.points[i].x - p.points[0].x;
        double y1 = p.points[i].y - p.points[0].y;
    
        double x2 = p.points[i+1].x - p.points[0].x;
        double y2 = p.points[i+1].y - p.points[0].y;
    
        double crossProduct = (x1 * y2) - (x2 * y1);
        
        tArea += crossProduct;
    }
    return (int)abs(tArea/2);
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Polygon p(n);
        for(int i=0; i<n; i++){
            cin >> p.points[i].x >> p.points[i].y;
        }
        
        cout << areaOfPolygon(p, n) << endl;
    }
    return 0;
}