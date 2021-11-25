/****
Totient Function

You are given an integer N and are supposed to find the value of Euler toient function for N phi(N)
Input Format:
First line of input will contain T(number of test case), each test case follows as.
An integer N in new line.
Output Format:
For each test case print the answer in new line
Constraints:
1 <= T <= 100
1 <= N <= 10^9
Sample Input:
2
20
21
Sample Output:
8 
12
***/

#include<bits/stdc++.h>
using namespace std;
typedef long long l;

//nlogn
void totientFunction(l n){
    l phi=n;
    for(l i=2; i<=sqrt(n); i++){
        if(n%i==0){
            while(n%i==0){ //checking if prime
                n=n/i;
            }
            phi=phi-phi/i;
        }
    }
    
    if(n>1){
        phi=phi-phi/n;
    }
    cout << phi << endl;
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        l n;
        cin >> n;
        totientFunction(n);
    }
    return 0;
}




/*

https://cp-algorithms.com/algebra/phi-function.html
https://www.amazon.jobs/en/jobs/1688564/software-development-engineer-amazon-wow-applications
https://www.amazon.jobs/en/jobs/1446556/software-development-engineer-1
https://www.amazon.jobs/en/jobs/1519581/software-development-engineer-intern
https://www.amazon.jobs/en/jobs/1688564/software-development-engineer-amazon-wow-applications
*/