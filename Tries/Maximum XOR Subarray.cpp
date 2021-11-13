/*****************
Maximum XOR Subarray

Given an array of N integers, find the subarray whose XOR is maximum.
Input Format:
First line of input contains an integer N, representing number of elements in array.
Next line contains N space-separated integers.
Constraints:
1 <= N <= 10^6
1 <= A[i] <=10^5 
Output Format:
Print XOR of the subarray whose XOR of all elements in subarray is maximum over all subarrays.
Sample Input 1:
4
1 2 3 4
Sample Output 1:
7
*****************/

#include<bits/stdc++.h>
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

int helper(int val, trieNode* head){
    int curr_xor = 0;
    trieNode* curr = head;
    
        for(int j=31; j>=0; j--){
            int b = (val >> j) & 1;
            
            if(b == 0){ //will move on right side
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
    return curr_xor;
}

int maximumXORSubarray(int *arr, int n){
    trieNode *head = new trieNode();
    int max_xor = INT_MIN;
    int prexor = 0;
    for(int i=0; i<n; i++){
        prexor = prexor ^ arr[i];
        insert(prexor, head);
        max_xor = max(max_xor, helper(prexor, head));
    }
    return max_xor;
}

int main(){
    
    int t;
    t = 1;
    while(t--){
        int n;
        cin >> n;
        int *arr = new int[n]();
        for(int i =0; i<n; i++){
            cin >> arr[i];
        }
        
        cout << maximumXORSubarray(arr, n) << endl;
        
        //free space
        delete[] arr;
    }
    return 0;
}
