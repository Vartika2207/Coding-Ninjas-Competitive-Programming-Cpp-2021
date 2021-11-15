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

double areaOfPolygon(Polygon p, int n){
    double tArea = 0;
    for(int i=1; i<n-1; i++){
        double x1 = p.points[i].x - p.points[0].x;
        double y1 = p.points[i].y - p.points[0].y;
    
        double x2 = p.points[i+1].x - p.points[0].x;
        double y2 = p.points[i+1].y - p.points[0].y;
    
        double crossProduct = (x1 * y2) - (x2 * y1);
        
        tArea += crossProduct;
    }
    return abs(tArea/2);
}

int main(){
    
    int t = 1;
    while(t--){
        string s;
        cin >> s;
        
        int n = s.size();
        int *arr = new int[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        
        Points p1;
        p1.x = 10;
        p1.y = 10;
        
        Polygon p(n);
        p.points[0] = p1;
        
        for(int i=1; i<n; i++){
            if(s[i-1] == 'N'){
                p.points[i].x = p.points[i-1].x;
                p.points[i].y = p.points[i-1].y + arr[i-1];
            }
            else if(s[i-1] == 'S'){
                p.points[i].x = p.points[i-1].x;
                p.points[i].y = p.points[i-1].y - arr[i-1];
            }
            else if(s[i-1] == 'W'){
                p.points[i].x = p.points[i-1].x - arr[i-1];
                p.points[i].y = p.points[i-1].y;
            }
            else if(s[i-1] == 'E'){
                p.points[i].x = p.points[i-1].x + arr[i-1];
                p.points[i].y = p.points[i-1].y;
            }
        }
        cout << (long long)areaOfPolygon(p, n) << endl;
    }
    return 0;
}