/***
Innocent Swaps and His Emotions

There are only three phases in Swaps life: Sleep, Play and Study. Also, there are two types of emotions Swaps experiences: Happy and Sad. Each phase of his life brings either kind of emotions.
The sleep and the play phase makes Swaps happy whereas the study phase makes him sad. Quite obvious, isn't it? But we know that life isn't that great, one cannot be happy all the time.
Swaps, being a very sensitive guy, doesn't like to mix his emotions on a particular day. So each day, he is in exactly one of the three phases.
Given N which denotes the number of days and K which denotes the exact number of days Swaps needs to be happy out of these N days, can you tell him in how many ways can he achieve this? Since the output value can be very large, take modulo with 1000000007(10^9+7)
Input Format:
The first line of the input contains T, denoting the number of test cases.

The next T lines contain two space-separated integers N and K.
Constraints:
1 <=T <= 10^5
1<= K <= N <= 10^6
Output Format:
For each test-case, output a single integer, the number of ways modulo 1000000007(10^9+7).
Sample Input 1:
3
1 1
2 1
3 2
Sample Output 2:
2
4
12
Explanation
In the first test case, he needs to feel joyful on Day 1. Hence, answer is 2 (He can either play video games or sleep).

In the second test case, he can be joyful either on Day 1 or Day 2. So number of ways = 4.
***/
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define max 1000001

lli mod = 1000000007;
/***********find factorial****************/
lli *fact = new lli[max];
void factorial(){
    fact[0] = 1;
    fact[1] = 1;
    lli i;
    for(i=2; i<max; i++){
        fact[i] = (fact[i-1] % mod * i % mod) % mod; 
    }
}
/***************************/

/************finding modular exponentiation - O(n)***************/
lli m_exponentiation(lli a, lli b){
    if(a == 0 || a == 1)
        return a;
    if(b == 0)
        return 1;
    lli ans ;
    if(b%2 == 0){
        lli smallAns = m_exponentiation(a, b/2);
        ans = (smallAns*smallAns) % mod;
    }
    else{
        lli smallAns = m_exponentiation(a, b-1);
        ans = (a % mod);
        ans = (ans*smallAns) % mod;
    } 
    return (ans + mod) % mod; //(ans < 0 ? (ans + c) %c : ans);
}
/***************************/

/************inverse modulus***************/
lli mod_inverse(lli factorial_k){
    return m_exponentiation(factorial_k, mod-2) % mod;
}
/***************************/

/***************************/
lli nCk(lli n, lli k){
    return (fact[n] % mod * (mod_inverse(fact[k]) % mod * mod_inverse(fact[n-k]) % mod) % mod) % mod;
}
/***************************/

lli number_of_ways(lli n, lli k){
    if(k > n)
        return 0;
    lli ways;
    //ways can be 2^k * nCk
    lli power_2k = m_exponentiation(2, k); //2^k % mod
    lli nCk_ = nCk(n, k);
    
    ways = power_2k % mod;
    ways = (ways % mod * (nCk_ % mod) ) % mod;
    return ways;
}

int main(){
    factorial();
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        lli n, k; //n is number of days, k is exact number of days Swaps needs to be happy out of these n days
        cin >> n >> k;
        cout << number_of_ways(n, k) << endl;
    }
    return 0;
}
