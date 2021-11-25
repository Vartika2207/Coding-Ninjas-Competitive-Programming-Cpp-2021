/***
Strange order

Given an integer n . Initially you have permutation p of size n : p[i] = i . To build new array a from p following steps are done while permutation p is not empty:
Choose maximum existing element in p and define it as x ; Choose all such y in p that gcd ( x , y ) ≠ 1 ; Add all chosen numbers into array a in decreasing order and remove them from permutation. Your task is to find a after p became empty.
Note: gcd ( a , b ) is the greatest common divisor of integers a and b .
Input format
Input contains single integer n — the size of permutation p p.
Output format
Print n integers — array a .
Constraints:
1 <= N <= 10^5
Sample Input:
5
Sample Output:
5 4 2 3 1
Explanation
It's needed 4 iterations to create array a:
Add 5
Add 4 and 2
Add 3
Add 1
***/

#include<bits/stdc++.h>
using namespace std;
typedef int l;


void seive(vector<int> &prime, int size){
    for(int i = 0; i <= size; i++){
        prime[i] = i;
    }
    for(int i=2; i<=sqrt(size); i++){
        if(prime[i] == i){
            for(int j=i*i; j<=size; j=j+i){
                if(prime[j] > i){
                    prime[j] = i;
                }
            }
        }
    }
}



//printing nums acc to gcd(x,y)!=1
void getMark(int num, bool *mark, vector<int> &prime){
    vector<int>temp_perm;

    temp_perm.push_back(num);
    
    mark[num]=true;
    
    int f = prime[num];
    int x = num;
    while(x != 1){
        int i=num-f;
        while(i>=1){
            if(!mark[i]){
                mark[i]=true;
                temp_perm.push_back(i);   
            }
            i=i-f;
        }
        while(x % f == 0){
            x = x/f;
        }
        f = prime[x];
    }
    
    //sorting temp_perm
    sort(temp_perm.begin(), temp_perm.end(), greater <int>());
    
    //printing temp_perm
    for(auto const &i:temp_perm){
        cout << i << " ";
    }
    return;
}



//to find all nums from n to 1
void strangeNum(int n, vector<int> &prime){
    bool *mark=new bool[n+1];
    for(int i=0; i<=n; i++){
        mark[i]=false;
    }
    for(int i=n; i>=1; i--){
        if(mark[i])
            continue;
        else
            getMark(i, mark, prime);
    }
    //free memeory for mark
    delete []mark;
}


int main(){
    int n;
    cin >> n;
    
    int size;
    size=n;
    
	vector<int>prime(size+1, 0);
    seive(prime, size);
   
    strangeNum(n, prime);
    return 0;
}