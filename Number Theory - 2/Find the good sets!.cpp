/****
Find the good sets!

You are given array a consisting of n distinct integers. A set s of numbers is called good if you can rearrange the elements in such a way that each element divides the next element in the order, i.e. 'si' divides 'si + 1', such that i < |s|, where |s| denotes size of set |s|.
Find out number of distinct good sets that you can create using the values of the array. You can use one value only once in a particular set; ie. a set cannot have duplicate values. Two sets are said to be different from each other if there exists an element in one set, which does not exist in the other.
As the answer could be large, print your answer modulo 10^9 + 7.
Input Format:
First line of the input contains an integer T denoting the number of test cases. T test cases follow.

First line of each test case contains an integer n denoting number of elements in array a.

Next line contains n space separated integers denoting the elements of array a.
Output Format:
For each test case, output a single line containing the corresponding answer.
Constraints
1 ≤ T ≤ 10
1 ≤ n ≤ 10^5
1 ≤ ai ≤ 10^5
All the elements of array a are distinct.
Input
2
2
1 2
3
6 2 3
Output:
3
5
Explanation
Test case 1. There are three sets which are good {1}, {2}, {1, 2}.

Test case 2. There are five sets which are good {6}, {2}, {3}, {6 2}, {6, 3}.
****/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define max 100000+1

void goodSet(vector<int>& arr, int n){
    int *seive=new int[max];
    for(int i=0; i<max; i++){
        seive[i]=0;
    }
    for(int i=0; i<n; i++){
        seive[arr[i]]=1;
    }
    
    for(int i=1; i<max; i++){
      if(seive[i]!=0){
        for(int j=i*2; j<max; j=j+i){
            if(seive[j]>0){
                seive[j]=(seive[j]%mod + seive[i]%mod)%mod;
            }
          }
       } 
    }

    int count=0;
    for(int i=0;i<max; i++){
        count = (count%mod + seive[i]%mod)%mod;
    }
    cout << count << endl;
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        goodSet(arr, n);
    }
    return 0;
}
