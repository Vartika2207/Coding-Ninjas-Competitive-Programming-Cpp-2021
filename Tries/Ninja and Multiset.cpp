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