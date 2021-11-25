/****
Boring Factorials

Sameer and Arpit want to overcome their fear of Maths and so they have been recently practising Maths problems a lot. Aman, their friend has been helping them out. But as it goes, Sameer and Arpit have got bored with problems involving factorials. Reason being, the factorials are too easy to calculate in problems as they only require the residue modulo some prime and that is easy to calculate in linear time. So to make things interesting for them, Aman - The Mathemagician, gives them an interesting task. He gives them a prime number P and an integer N close to P, and asks them to find N! modulo P. He asks T such queries.
Input Format:
First line contains an integer T, the number of queries asked.
Next T lines contains T queries of the form “N P”. (quotes for clarity)
Output Format:
Output exactly T lines, containing N! modulo P.
Constraints:
1 <= T <= 1000
1 < P <= 2*10^9
1 <= N <= 2*10^9
Abs(N-P) <= 1000
Sample Input:
3
2 5
5 11
21 71
Sample Output:
2
10
6
***/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;


lli exponentiation(lli a, lli b, lli c){
    if(a == 0)
        return 0;
    if(b == 0)
        return 1;
    lli ans ;
    if(b%2 == 0){
        lli smallAns = exponentiation(a, b/2, c);
        ans = (smallAns*smallAns) % c;
    }
    else{
        lli smallAns = exponentiation(a, b-1, c);
        ans = (a % c);
        ans = (ans*smallAns) % c;
    } 
    return (ans + c) % c;  //ans < 0 ? (ans + c)%c : ans;
}

lli wilson_Boring_factorials(lli n, lli p){
    
    if(n >= p)
        return 0; //becz n! will contain p in it and mod p will make it 0
    
    lli ans, fact = 1;
    //according to wilson thrm
    //n! modp = -[(n+1)^-1*.....(p-1)^-1] mod p = x modp , p>n
    //=>LHs = -x^-1 modp ------eqn1
    //applying fermet
    //LHS: -x^-1 modp = -x^(p-2) modp + p
    for(lli i=n+1; i<p; i++){
        fact = (fact * i) % p;
    }
    ans = exponentiation(fact, p-2, p); // we need fact^(p-2) mod p
    return p-ans;
}


int main(){
    
    int t;
    cin >> t;
    while(t--){
        lli n, p;
        cin >> n >> p;
        cout << wilson_Boring_factorials(n, p) << endl;
    }
    return 0;
}