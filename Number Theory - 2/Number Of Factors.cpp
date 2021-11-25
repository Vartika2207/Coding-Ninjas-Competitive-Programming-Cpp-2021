/****
Number Of Factors

A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
Input Format:
First line of input will contain T(number of test cases), each test case follows as.
Each test cases consists of a single line containing integers a, b, and n as described above.
Output Format:
Output for each test case one line containing the number of n-factorful integers in [a, b].
Constraints:
1 <= T <= 10000
1 ≤ a ≤ b ≤ 10^6
0 <= b - a <= 100
0 ≤ n ≤ 10
Sample Input
4
1 3 1
1 10 2
1 10 3
1 100 3
Sample Output
2 
2
0
8
****/

#include<bits/stdc++.h>
using namespace std;
#define max 1000000+1

//time O(nloglogn)
void sieve(vector<int>&prime){
    for(int i=2; i<=max; i++){    // n times
        if(prime[i]==0){
            prime[i]=1;
            for(int j=i*2; j<=max; j=j+i){ //loglogn
                prime[j]++;
            }
        }
    }
}
/******time: O(t) *(b-a)=> O(t*b)******/
int nfactorful_numbers(int s, int e, int n, vector<int>&prime){
    int n_factorful=0;
    for(int i=s; i<=e; i++){
        if(prime[i]==n)
            n_factorful++;
    }
    return n_factorful;
}
/************/

/*********better time :  O(t) * O(b-a) = O(t*1) *******/
void usingPreComputedTable(vector<int>&prime, vector<vector<int>>&table){
    for(int i=1; i<=10; i++){
        for(int j=2; j<=max; j++){
            if(prime[j]==i){
                table[i][j]=table[i][j-1]+1;
            }
            else{
                table[i][j]=table[i][j-1];
            }
        }
    }
}

/****************/
int main(){
    
    //gives distinct prime factors of each numbers
    vector<int> prime(max, 0);
    sieve(prime);
    
    vector<vector<int>>table(11, vector<int>(max, 0));
    usingPreComputedTable(prime, table);
    
    int t;
    cin>>t;
    while(t--){
        int s, e, f;
        cin >> s >> e >> f;
        cout<< table[f][e]-table[f][s-1]<<endl;             //time : O(seive + table_function + t*1)
        //cout << nfactorful_numbers(s, e, f, prime)<<endl;  //time : O(sieve + t*(b))
    }
}