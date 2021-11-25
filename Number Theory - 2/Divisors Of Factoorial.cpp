/****
Divisors Of Factorial

Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.
Input Format:
The first line contains T, number of test cases.
T lines follow each containing the number N.
Output Format:
Print T lines of output each containing the answer.
Constraints
1 <= T <= 500
0 <= N <= 50000
Sample Input:
3
2
3
4
Sample Output:
2
4
8
****/

#include<bits/stdc++.h>
using namespace std;
#define mode 1000000007

long factorialDivisors(int n){
    if(n<=0) return 1;
    
    //fnding all prime number under n
    vector<bool>prime(n+1, true);
    for(int i=2;i<=sqrt(n);i++){
        if(prime[i])
            for(int j=i*i; j<=n;j=j+i)
                prime[j]=false;
    }
    //all numbers are prime for which prime[i]=true
    
    //counting divisors or prime 
    long divisors=1;
    for(int i=2;i<=n;i++){
        if(prime[i]){
            long a=n/i;
            for(int j=i*i; j<=n; j=i*j){
                a+=n/j;
            }
            divisors=(divisors%mode * (a+1)%mode)%mode;
        }
    }
    return divisors;
    
}

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<factorialDivisors(n)<<endl;
    }
    return 0;
}