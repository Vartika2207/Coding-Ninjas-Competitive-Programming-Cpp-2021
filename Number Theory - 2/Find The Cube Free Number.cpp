/****
Find The Cube Free Number

A cube free number is a number who’s none of the divisor is a cube number (A cube number is a cube of a integer like 8 (2 * 2 * 2) , 27 (3 * 3 * 3) ). So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc (we will consider 1 as cube free). 8, 16, 24, 27, 32 etc are not cube free number. So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3 and position of 10 is 9. Given a positive number you have to say if its a cube free number and if yes then tell its position among cube free numbers.
Note: we will consider 1 as the 1st cube free number
Input Format:
First line of the test case will be the number of test case T 
Each test case contain an integer N
Output Format:
For each test case print the position of N in cube free numbers and if its not a cube free number print "Not Cube Free" in a newline.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^6
Sample Input:
10
1
2
3
4
5
6
7
8
9
10
Sample Output:
1
2
3
4
5
6
7
Not Cube Free
8
9
****/
#include<bits/stdc++.h>
using namespace std;
#define max 1000000+1


void cubeFree(vector<int>& arr){
    arr[1]=1;
    for(int i=2; i<=100; i++){
        int currCube=i*i*i;
        for(int j=1; j*currCube<=max; j=j+1){
            arr[j*currCube]=-1; //not cube free
        }
    }
    
    //assigning position to cube free number
    int position=1;
    for(int i=1;i<=max;i++){
        if(arr[i]!=-1){
            arr[i]=position;
            position++;
        }
    }
}

void positionForCFN(int n, vector<int>&arr){
    if(arr[n]==-1){
        cout<<"Not Cube Free"<<endl;
        return;
    }
    else 
        cout<<arr[n]<<endl;
}

/* giving TLE
void positionForCFN(int n){
    if(n==1){ 
        cout<<1<<endl;
        return;
    }
    //fnding all prime number under n
    vector<bool>prime(n+1, true);
    for(int i=2;i<=cbrt(n);i++){
        if(prime[i])
            for(int j=i*i; j<=n;j=j+i)
                prime[j]=false;
    }
    //all numbers are prime for which prime[i]=true
    
    //if the number is not cube free
    for(int i=2;i<=cbrt(n);i++){
        if(prime[i]){
            int cube=i*i*i;
            if(n%cube==0){
                cout<<"Not Cube Free"<<endl;
                return ;
            }
        }
    }
    
    
    //find position
    long position=0;
    for(int i=2;i<=cbrt(n);i++){
        if(prime[i]){
            int cube=i*i*i;
            position+=n/cube;
        }
    }
    cout << n-position<<endl;;
    
}
*/

int main(){
    vector<int>arr(max, 0);
    cubeFree(arr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        positionForCFN(n, arr); 
    }
    return 0;
}
