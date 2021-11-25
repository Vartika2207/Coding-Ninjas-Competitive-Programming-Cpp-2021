/****
Sehwag and ETF

Sehwag has been solving a lot of mathematical problems recently. He was learning ETF (Euler Totient Function) and found the topic quite interesting. So, he tried solving a question on ETF. He will be given two numbers L and R. He has to find the probability that the ETF of a number in the range [L, R] is divisible by a number K.
Input Format:
The first line contains an integer T, representing the number of test cases.
The next T lines will contain three integers L, R and K.
Constraints:
1 <= T <= 10
1 <= L <= R <= 10^12
0 <= R - L <= 10^5
1 <= K <= 10^6
Output Format:
Print the answer in a new line after rounding off the first 6 digits after the decimal place.
Sample Input 1:
3
1 4 2
2 5 2
3 10 4
Sample Output 1:
0.500000
0.750000
0.375000
***/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define maxSize 1100001
#define arrSize 1100001
/******calcilating and storing all prime nums til 1e6*******/
lli *prime = new lli[arrSize];
void sieveEth(){
    bool *sieve = new bool[arrSize];
    for(lli i=1; i<arrSize; i++){
        sieve[i] = true;
    }
    for(lli i=2; i<sqrt(arrSize) ;i++){
        if(sieve[i]){
            for(lli j=i*i; j<arrSize; j+=i){
                sieve[j] = false;
            }
        }
    }
    
    //storeing preime numbers in prime array
    prime[0] = 2;
    lli index = 1;
    for(lli i=3; i<arrSize; i+=2){
        if(sieve[i]){
            prime[index++] = i;
        }
    }
}
/************/

//find probability that the ETF of a number in the range [L, R] is divisible by a number K.
double prob_etf_divisible_by_k(lli l, lli r, lli k){
    if(k == 1){
        return 1; //here prob is 1
    }
    sieveEth();
    lli *primeSegmented = new lli[r - l + 1];
    lli *phiSegmented = new lli[r - l + 1];
    for(lli i=l; i<=r; i++){
        primeSegmented[i-l] = i;
        phiSegmented[i-l] = i;
    }
    //sefmented sieve
    for(lli i=0; prime[i]<=sqrt(r); i++){
        lli currPrime=prime[i];
        lli base=(l/currPrime)*currPrime;    //base is closest multiple of currPrime
        
        if(base<l){
            base+=currPrime;   //eg l=100, currPrime=3 =>base=99 hence base=99+3 as closest multiple of 3 from l
        }
        for(lli j=base; j<=r; j+=currPrime){
            while(primeSegmented[j-l] % currPrime==0){
                primeSegmented[j-l] /= currPrime;
            }
            phiSegmented[j-l] = phiSegmented[j-l] - phiSegmented[j-l]/currPrime;
        }
    }
    //aftersegmented sieve i prime is left which we know is greater that srqt(r)
    //to find that one missing prime for getting exact phi
    for(lli i=l; i<=r; i++){
        if(primeSegmented[i-l] > 1){
            phiSegmented[i-l] = phiSegmented[i-l] - phiSegmented[i-l]/primeSegmented[i-l];
        }
        primeSegmented[i-l] = 1;
    }
    
    //counting ETF of a number in the range [L, R] is divisible by a number K.
    //traversing on phiSegmented
    lli count_for_etf_divisible_by_k= 0;
    for(lli i=l; i<=r; i++){
        if(phiSegmented[i-l] % k ==0)
            count_for_etf_divisible_by_k++;
    }
    
    double probability = (double)count_for_etf_divisible_by_k / (r - l + 1);
    //free all space
    delete[] phiSegmented, phiSegmented;
    return probability;
    
}

int main(){
	int t;
    cin >> t;
    while(t--){
        lli r, l, k;
        cin >> l >> r >> k;
        cout << fixed << setprecision(6) << prob_etf_divisible_by_k(l, r, k) << endl;
    }
    return 0;
}