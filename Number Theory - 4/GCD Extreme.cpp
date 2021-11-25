/***
GCD Extreme

Given the value of N, you will have to find the value of G. The meaning of G is given in the following code
G=0;
for(i = 1 ; i < N ; i++)
   for(j = i+1 ; j <= N ; j++) 
       G+=gcd(i,j);
Here gcd() is a function that finds the greatest common divisor of the two input numbers.
Input Format:
The first line of input will contain T(number of the test case). Each test case contains an integer N.
Output Format:
For each test case print the answer in a new line.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^5
Sample Input:
3
10
100
3
Sample Output:
67
13015
3
***/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define maxSize 100001

/**************/
//time : O(n^2logn)
lli gcdExtremeBrute(int n){
    lli gcd = 0;
    for(int i=1; i<n; i++)
       for(int j=i+1; j<=n; j++) 
           gcd += __gcd(i,j);
    
    return gcd;
}
/*************/


/**********time=O(lgn)****************/
lli *phi = new lli[maxSize];
lli *result = new lli[maxSize]();
lli *gcd = new lli[maxSize]();
lli gcdExtremeBetter(){
    //calculating phi
    phi[0] = 0;
    for(int i=1; i<maxSize; i++){
        phi[i] = i;
    }
    for(int i=2; i<maxSize; i++){
        if(phi[i] == i){
            phi[i] = i-1;
            for(int j=2*i; j<maxSize; j+=i){
                phi[j] = phi[j] - phi[j]/i;
            }
        }
    }
    /***phi calculated**/
    
    /**finding sigma(d * phi(n/d))**/
    for(int i=1; i<maxSize ;i++){
        for(int j=2; j*i<maxSize; j++){
            result[i*j] += i*phi[j]; //i*phi(i*j /i)==d*phi(n/d)
        }
    }
    //finding gcd sum
    gcd[1] = 0;
    for (int i = 2; i < maxSize; i++)
        gcd[i] = gcd[i - 1] + result[i];
}


/*************************/
int main(){
    int t;
    cin >> t;
    gcdExtremeBetter();
    while(t--){
        int n;
        cin >> n;
        cout << gcd[n] << endl;
    }
    return 0;
}