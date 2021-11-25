/***
Sum of LCM

Given n, calculate and print the sum :
LCM(1,n) + LCM(2,n) + .. + LCM(n,n)
where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
Input Format :
First line of input will contain T(number of test case), each test case follows as.
An Integer N
Output Format :
Required sum for each test case in newline.
Constraints :
1 <= T <= 10^4
1 <= n <= 10^5
Sample Input 1 :
1
5
Sample Output 1 :
55
Sample Input 2 :
1
2
Sample Output 2 :
4
***/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define max 100000+1

/************/
//using LCM(a, b)=(a * b) / gcd(a, b) 
ll sumLcm(ll n){
    ll sum=0;
    for(ll i=1; i<n; i++){
        sum+=n*n / __gcd(i,n);
    }
    sum=sum+2*n;
    return sum/2;
}

//just calling sumLcm(n)
/*************/

/*********BETTER**********/
//nlog n
ll *phi=new ll[max], *pre=new ll[max];
void etf(){
    
    //finding phi(i) in nlogn
    for(ll i=1; i<=max; i++){
        phi[i]=i;
    }
    for(ll i=2; i<=max; i++){   
        if(phi[i]==i){
            phi[i]=i-1;
            for(ll j=i*2; j<=max; j+=i){
                phi[j]-=phi[j]/i;
            }
        }
    }
    
}

ll LCMsum(){
    etf();
    //finding i*phi(i)
    for(ll i=1; i<=max; i++){
        for(ll j=i; j<=max; j+=i){
            pre[j]+=i*phi[i];
        }
    }
    // //calculating sum = (d*phi(d) + 1)*n / 2
    // ll lcm_sum=pre[n];
    // lcm_sum=(lcm_sum+1)*n;
    // lcm_sum/=2;
    // return lcm_sum;
    
}

/*******************/


int main(){
    
    int t;
    cin >> t;
    LCMsum();
    while(t--){
        ll n;
        cin >> n;
        
        //calculating sum = (d*phi(d) + 1)*n / 2
        ll lcm_sum=pre[n];
        lcm_sum=(lcm_sum+1)*n;
        lcm_sum/=2;
        cout << lcm_sum <<endl;
        }
    
    return 0;
}