/***************
Ninja and Multiset

Our problem setter, Ninja, is fascinated by different types of sets. Quite recently, he came across a new term- Multiset. Multiset is a set, where equal elements are allowed. He started experimenting with it and has managed to frame a pretty interesting problem for you to solve.
You are given a multiset G, initially containing only 0, and a few queries q. Queries are actually of 3 types:
"+ x" — This query adds an integer x to the given multiset.
"- x" — This query erases one occurrence of x from the given multiset. Before this query is encountered, it is guaranteed that the multiset will contain integer x at least once.
"? x" — In this query, you are given integer x and you need to compute the maximum value of bitwise exclusive OR (also known as XOR) of integer x and some integer y from the given multiset.
Input Format:
First line on input contain Q (number of queries ).
Next Q line contain Q queries as defined above.
Output Format:
For each query of type '?' print the answer in new line
Constraints:
1 <= Q <= 10^5
1 <= x <= 10^9
Sample Input 1:
8
? 8
? 5
+ 10
? 5
? 4
+ 4
- 4
? 10
Sample Output 1:
8
5
15
14
10
Explanation:
Initially the multiset contains only the integer 0. So for the first query, answer is 8 XOR 0 = 8.
Similarily, the answer for second query is 5 XOR 0 = 5.
After the third query, 10 is added to the multiset.
For the fourth query, 5 will be XOR'ed with 0 and 10. Out of these, 5 XOR 10 = 15 is max.
Similarily, for the fifth query, 4 will be XOR'ed with 0 and 10. Out of these, 4 XOR 10 = 14 is max.
After the sixth query, 4 is added to the multiset.
After the seventh query, 4 is erased from the multiset.
For the last query, 10 is XOR'ed with 0 and 10. Out of these, 10 XOR 0 = 10 is max.
****************/
#include<bits/stdc++.h>
using namespace std;

struct trieNode{
    trieNode* left; // carry 0 bit
    trieNode* right; // carry 1 bit
};

void insert(trieNode* root, int x){
    trieNode* temp = root;
    for(int i=31; i>=0; i--){
        int bit = (x >> i) & 1;
        
        if(bit == 0){
            if(!temp->left){
                temp->left = new trieNode();
            }
            temp = temp->left;
        }
        else{
            if(!temp->right){
                temp->right = new trieNode();
            }
            temp = temp->right;
        }
    }
}


int get_xor(trieNode* head, int n){
   
    trieNode* curr = head;
    int curr_xor = 0;
    for(int j=31; curr != NULL && j>=0; j--){
        int b = (n >> j) & 1;

        if(b == 0){ //will move on side
            if(curr->right){
                curr_xor += pow(2, j);
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        else{ //will move on left side
            if(curr->left){
                // curr_xor += pow(2, j);
                curr = curr->left;
            }
            else{
                curr = curr->right;
                curr_xor += pow(2, j);
            }
        }
    }
    
    return curr_xor ^ n;
}

trieNode* remove(trieNode* root, int x, int i){
    if(!root || i < 0)
        return nullptr;
    
    int bit = (x >> i) & 1;
    if(bit == 0){
        root->left = remove(root->left, x, i - 1);
    }
    else{
        root->right = remove(root->right, x, i - 1);
    }
    
    if(!root->left && !root->right){
        delete root;
        return NULL;
    }
    return root;
}

int main(){
    
    int t;
    t  =1;
    while(t--){
        trieNode* root = new trieNode();
        int q;
        cin >> q;
        unordered_map<int, int> mp; // stored num frequency
        while(q--){
            char symbol;
            cin >> symbol;
            int num;
            cin >> num;
            insert(root, 0);
            
            switch(symbol){
                case '?':
                    cout << get_xor(root, num) << endl;
                    break;
                case '+':
                    insert(root, num);
                    mp[num]++;
                    break;
                case '-':
                    if(mp[num] == 1){
                        root = remove(root, num, 31);
                        mp[num]--;
                    }
                    else{
                        mp[num]--;
                    }
                    break;
            }
        }
    }
    return 0;
}
