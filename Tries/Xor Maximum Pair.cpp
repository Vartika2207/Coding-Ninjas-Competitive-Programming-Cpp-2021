#include <bits/stdc++.h>
using namespace std;

struct trieNode{
    trieNode* left; //carry 0 bit
    trieNode* right; //carry 1 bit
};

void insert(int n, trieNode* head){
    trieNode* curr = head;
    for(int i=31; i>=0; i--){
        int b = (n >> i) & 1;
        
        if(b == 0){
            if(!curr->left){
                curr->left = new trieNode();
            }
            curr = curr->left;
        }
        else{
            if(!curr->right){
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }
}

int findMaxXorPair(trieNode* head, int* arr, int n){
    int max_xor = INT_MIN;
    
    for(int i=0; i<n; i++){
        int val = arr[i];
        trieNode* curr = head;
        int curr_xor = 0;
        for(int j=31; j>=0; j--){
            int b = (val >> j) & 1;
            
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
                    curr_xor += pow(2, j);
                    curr = curr->left;
                }
                else{
                    curr = curr->right;
                }
            }
        }
        max_xor = max(max_xor, curr_xor);
    }
    
    return max_xor;
}

int main() {
    int arr[6] = {8, 1, 2, 15, 5, 10};
    trieNode* head = new trieNode();
    for(int i=0; i<6; i++){
        insert(arr[i], head);
    }
    
    cout << findMaxXorPair(head, arr, 6) << endl;;
    
    return 0;
}