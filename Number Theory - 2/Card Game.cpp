/****
Card Game
Send Feedback
Vova again tries to play some computer card game.
The rules of deck creation in this game are simple. Vova is given an existing deck of n cards and a magic number k. The order of the cards in the deck is fixed. Each card has a number written on it; number ai is written on the i-th card in the deck.
After receiving the deck and the magic number, Vova removes x (possibly x = 0) cards from the top of the deck, y (possibly y = 0) cards from the bottom of the deck, and the rest of the deck is his new deck (Vova has to leave at least one card in the deck after removing cards). So Vova's new deck actually contains cards x + 1, x + 2, ... n - y - 1, n - y from the original deck.
Vova's new deck is considered valid iff the product of all numbers written on the cards in his new deck is divisible by k. So Vova received a deck (possibly not a valid one) and a number k, and now he wonders, how many ways are there to choose x and y so the deck he will get after removing x cards from the top and y cards from the bottom is valid?
Input
The first line contains two integers n and k (1 ≤ n ≤ 100 000, 1 ≤ k ≤ 10^9).

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 10^9) — the numbers written on the cards.
Output
Print the number of ways to choose x and y so the resulting deck is valid.
Sample Input 1
3 4
6 2 8
Sample Output 1
4
Sample Input 2
3 6
9 1 14
Sample Output 2
1
****/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
    ll n,k;
    cin>> n >> k;
    ll arr[n];
    
    for(ll i = 0; i<n ;i++){
        cin>>arr[i];
    }
    
    vector<pair<int,int>> vp;
    ll temp_k = k;
        for(int i = 2; i*i<=temp_k ;i++){
            
            if(temp_k%i == 0){
                int count = 0;
                while(temp_k%i == 0){
                    temp_k/=i;
                    count++;
                }
                vp.push_back({i,count});
                
            }
        
        }
    
    
    if(temp_k!=1){
        vp.push_back({temp_k,1});
    }
    
    
    ll ans = 0;
    
    vector<pair<int,int>> vq;
    for(int i=0;i<vp.size();i++){
        // cout<<vp[i].first<<" ";
        vq.push_back({vp[i].first, 0});
        // cout<<vq[i].first<<endl;
    }
	int i = 0;
    int j = 0;
    while(i!=n){
        for(int z=0 ;z<vq.size();z++){
            temp_k = arr[i];
            int cn = 0;
            while(temp_k%vp[z].first == 0){
                temp_k/=vp[z].first;
                cn++;
            }
            vq[z].second +=cn;
        }
        
        bool done = true;
        
        for(int z= 0;z<vq.size();z++){
            if(vp[z].second > vq[z].second){
                done = false;
                break;
            }
        }
        if(done){
            ans += n-i;
            while(j<=i){
                for(int l=0 ;l<vq.size();l++){
                    temp_k = arr[j];
                    int cn = 0;
                    while(temp_k%vp[l].first == 0){
                        temp_k/=vp[l].first;
                        cn++;
                    }
                    vq[l].second -= cn;
                }
                
                bool done_2 = true;
                for(int l= 0;l<vq.size();l++){
                    if(vp[l].second > vq[l].second){
                        done_2 = false;
                        break;
                    }
                }
                
                if(done_2){
                    j++;
                    ans+=n-i;
                }
                else {
            		i++;
                    j++;
                    break;
                }
            }
        }
        else{
            i++;
        }
        
    }
    cout<<ans<<endl;
}
