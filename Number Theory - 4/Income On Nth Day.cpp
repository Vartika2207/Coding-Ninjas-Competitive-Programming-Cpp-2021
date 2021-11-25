/***
Income On Nth Day

Daulat Ram is an affluent business man. After demonetization, IT raid was held at his accommodation in which all his money was seized. He is very eager to gain his money back, he started investing in certain ventures and earned out of them. On the first day, his income was Rs. X, followed by Rs. Y on the second day. Daulat Ram observed his growth as a function and wanted to calculate his income on the Nth day.
The function he found out was FN = FN-1 + FN-2 + FN-1×FN-2
Given his income on day 0 and day 1, calculate his income on the Nth day (yeah Its that simple).
Input Format:
The first line of input consists of a single integer T denoting the number of test cases.
Each of the next T lines consists of three integers F0, F1 and N respectively.
Output Format:
For each test case, print a single integer FN, as the output can be large, calculate the answer modulo 10^9+7.
Constraints:
1 ≤ T ≤ 10^5
0 ≤ F0, F1, N ≤ 10^9
Sample Input :
2
0 1 2
1 2 4
Sample Output:
1
107
Explanation
In the second test case his income on day 0 is 1 and the income on day 1 is 2. We need to calculate his income on day 4.

F0=1

F1=2

F2=1 + 2 + 1×2 = 5

F3=2 + 5 + 2×5 = 17

F4=5 + 17 + 5×17 = 107
***/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli m = 1000000007;
/******finding fib(n)*****/
//tine:O(logn)
lli mod = 1000000007;

void multiply(lli A[2][2], lli B[2][2]){
    lli firstval = (A[0][0] * B[0][0] + A[0][1] * B[1][0])%(mod-1);
    lli secondval = (A[0][0] * B[0][1] + A[0][1] * B[1][1])%(mod-1);
    lli thirdval = (A[1][0] * B[0][0] + A[1][1] * B[1][0])%(mod-1);
    lli fourthval = (A[1][0] * B[0][1] + A[1][1] * B[1][1])%(mod-1);
    
    A[0][0] = firstval%(mod-1);
    A[0][1] = secondval%(mod-1);
    A[1][0] = thirdval%(mod-1);
    A[1][1] = fourthval%(mod-1);
    
}

void power(lli A[2][2], lli n){
    if(n == 0 || n == 1)
        return ;
    power(A, n/2);
    //multipy A^n/2  A^n/2
    multiply(A, A);
    if(n%2 != 0){
        lli B[2][2] = {{1, 1}, {1, 0}};
        multiply(A, B);
    }
}

//recursive
lli fib(lli n){
    if(n == 0)
        return 0;
    lli A[2][2] = {{1, 1}, {1, 0}};
    power(A, n-1);
    return A[0][0];
    
}

lli fib_iterative(lli n){
    if (n == 0 || n == 1 || n == 5)
        return n;
    if (n == 2)
        return 1;
    n--;
    lli a[2][2] = {1, 1,
                  1, 0};
    lli ans[2][2] = {
        1, 0,
        0, 1};
    lli temp[2][2];
    lli m = mod - 1, i, j, k;
    while (n)
    {
        if (n & 1)
        {
            //ans=ans*a
            for (i = 0; i < 2; i++)
                for (j = 0; j < 2; j++)
                {
                    temp[i][j] = 0;
                    for (k = 0; k < 2; k++)
                    {
                        temp[i][j] += a[i][k] * ans[k][j];
                        temp[i][j] %= m;
                    }
                }
            for (i = 0; i < 2; i++)
                for (j = 0; j < 2; j++)
                    ans[i][j] = temp[i][j];
        }
        //a=a*a
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                temp[i][j] = 0;
                for (k = 0; k < 2; k++)
                {
                    temp[i][j] += a[i][k] * a[k][j];
                    temp[i][j] %= m;
                }
            }
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
                a[i][j] = temp[i][j];
        n >>= 1;
    }
    return ans[0][0];
}

/****************/

/*******to find power********/
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

/***************/

lli income_nth_day(lli f0, lli f1, lli n){
    //g(n) = 1+f(n) 
    //g(n) = a^x * b^y
    //x = fib(n-1) mod(m-1)  && y = fib(n) mod(m-1)
    lli fib_n_1 = fib(n-1);//fib(n-1)
    lli fib_n   = fib(n); //fib(n)  
        
    lli x = fib_n_1 % (m-1);    
    lli y = fib_n % (m-1);  
    
    lli a = 1 + f0; //g(0) = 1+f(0)
    lli b = 1 + f1; //g(1) = 1+f(1)
    
    lli A = exponentiation(a, x, m); //A = a^x mod m
    lli B = exponentiation(b, y, m); //B = b^y mod m
    
    lli g_n = ((A % m) * (B % m)) % m; //g(n) = (A * B) mod m
    
    lli f_n = g_n - 1; //g(n) = f(n) + 1
    
    return f_n < 0 ? f_n + m : f_n;
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        lli f0, f1, n;
        cin >> f0 >> f1 >> n;
        cout << income_nth_day(f0, f1, n) << endl;
    }
    return 0;
}