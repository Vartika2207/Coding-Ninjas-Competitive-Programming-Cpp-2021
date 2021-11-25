/***
Segmented Sieve Problem

In this problem you have to print all primes from given interval.
Input Format:
First line of input will contain T(number of test cases), each test case follows as.

On each line are written two integers L and U separated by a blank. L - lower bound of 
interval, U - upper bound of interval.
Output Format:
For each test case output must contain all primes from interval [L; U] in increasing order.
Constraints:
1  <= T <= 100
1 <= L <= U <= 10^9
0 <= U - L <= 10^5
Sample Input:
2
2 10
3 7
Sample Output:
2 3 5 7
3 5 7 
***/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define max 100000+1
vector<int> *sieve(){
    bool *isPrime=new bool[max];
    for(int i=0; i<max; i++){
        isPrime[i]=true;
    }
    for(int i=2; i<sqrt(max); i++){
        if(isPrime[i]){
            for(int j=i*i; j<max; j+=i){
                isPrime[j]=false;
            }
        }
    }
    
    //storing all prime nums
    vector<int> *prime=new vector<int>();
    prime->push_back(2);
    for(int i=3; i<max; i+=2){
        if(isPrime[i]){
            prime->push_back(i);
        }
    }
    return prime;
}

void segmentedSeive(ll l, ll r, vector<int> *prime){
    bool *isPrime=new bool[r-l+1];
    for(int i=0; i<=r-l; i++){
        isPrime[i]=true;
    }
    
    for(int i=0; (ll)prime->at(i)<=sqrt(r); i++){
        int currPrime=prime->at(i);
        long long base=(l/currPrime)*currPrime;    //base is closest multiple of currPrime
        
        if(base<l){
            base+=currPrime;   //eg l=100, currPrime=3 =>base=99 hence base=99+3 as closest multiple of 3 from l
        }
        for(ll j=base; j<=r; j+=currPrime){
            isPrime[j-l]=false;
        }
        if(base == currPrime){
            isPrime[base-l]=true; //eg: l=2, currPrime=3=> base=0 and base=0+3
        }
    }
    
    //printing segmented primes
    for(int i=0; i<r-l+1; i++){
        if(isPrime[i]==true & i+l != 1){
            cout << i+l << " ";
        }
    }
    cout << endl;
    delete[] isPrime; //free space
}




int main(){
    
    vector<int> *prime=sieve();
    int t;
    cin >> t;
    while(t--){
        ll l, u;
        cin >> l >> u;
        segmentedSeive(l, u, prime);
    }
    return 0;
}