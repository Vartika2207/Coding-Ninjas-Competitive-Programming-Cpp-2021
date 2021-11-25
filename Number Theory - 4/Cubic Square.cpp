/***
Cubic Square

Varun is learning method of successive squaring so that he can calculate a^b mod m quickly. To give himself practice he wrote many tuples of a, b and m and went to school thinking that he will do it after school.
After school he found that tuples he wrote are modified by his little sister. His sister converted each b into base 3. Varun wrote everything in base 10.
Help Varun to do his exercise.
Input Format:
First line of input contains a number T(number of test case). Each test case contains an integer a(base 10) followed by a string b (base 3) followed by integer m (base 10). All are space-separated.
Output Format;
Output a number for each test case a^b mod m in base 10 in new line.
Constraints:
1 <= T <= 1000
1 <= a, m <= 10^9
Number of digits in b will be less than 250.
Sample Input:
2
2 10 10
3 21101 19
Sample Output:
8
3
***/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

/******************modular exponentn -method1***************************/
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

/******conveting base 3 to base 10******/
lli base3_to_base10(lli b_base3){
    lli ans = 0, power_3 =1; //3^0=1
    lli n = b_base3;
    while(n){
        lli lastDigit = n%10;
        ans += lastDigit * power_3;
        power_3 *= 3;
        n = n/10;
    }
    return ans;
}

lli cs(lli a, lli b_base3, lli m){
    //converting b of base3 to b base10
    lli b_base10 = base3_to_base10(b_base3);
    return exponentiation(a, b_base10, m);
}
/**********************************************************************/

/**********better********modified modular exponentn -method1*****************/
lli cs_modified(lli a, string b_base3, lli m){
    lli ans =1;
    for(int i=b_base3.length()-1; i>=0; i--){
        if(b_base3[i] == '0'){	
			a = a %  m;
			a = (((a * a) %m) * a) % m;
		}
        if(b_base3[i] == '1'){
            ans = (ans * a)% m;
            a = (((a * a) %m) * a) % m;
        }
        if(b_base3[i] == '2'){
            ans = ((ans * a) % m * a) % m;
            a = (((a * a) %m) * a) % m;
        }
    }
    return ans;
}

/**********************************************************************/


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        lli a, m; //base 10
        string b_base3;
        cin >> a >> b_base3 >> m;
        cout << cs_modified(a, b_base3, m); //gives a^b % m
        cout << endl;
        
    }
    return 0;
}