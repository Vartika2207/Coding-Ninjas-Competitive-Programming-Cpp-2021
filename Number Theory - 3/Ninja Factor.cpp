/***
Ninja Factor

Ninja is given an array of integers of size N and Q queries, each query will be consists of two integers l, r and ninja is supposed to calculate the number of i such that the ninja factor of array[i] is a prime number where l <= i <= r
Ninja factor of a Number A is defined as the number of integers B such that
1 <= B <= A
LCM (A, B) = A * B
Input Format:
 Line1: contain two space-separated integers N and Q denoting the number of elements in array and number of queries.
Line2: contain N space-separated integers denoting the elements of the array
Next, Q lines contain two space-separated integers l, r describing the query.
Output Format:
For each query print the answer in a newline.
Constraints:
1 <= N , Q <= 10^5
1 <= arr[i] <= 10^9
1 <= l, r <= N
Sample Input:
10 6
8 8 6 8 6 7 10 7 9 9 
2 10
7 7
5 7
7 8
6 10
3 4
Sample Output:
2
0
1
0
0
1
***/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int q, n;
    cin >> n >> q;
    
    int *dp = new int[n+1]();
    ll arr;
    for(int i=1; i<=n; i++){
        cin >> arr;
        if(arr == 3 || arr == 4 || arr == 6)
            dp[i] = 1;
        dp[i] += dp[i-1];
    }
    
    int l, r;
    while(q--){
        cin >> l >> r;
        cout << dp[r] - dp[l-1] << "\n";
    }
    //free space
    delete[] dp;
    return 0;
}




















