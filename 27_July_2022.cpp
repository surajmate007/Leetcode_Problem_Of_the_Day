// Leetcode:
// Flatten Binary Tree to Linked List with preorder traversal.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* head;
    
    void getAns(TreeNode* root, TreeNode* lft, TreeNode* rgt){
        if(root == NULL){
            return;
        }
        
        if(head == NULL){
            head = root;
            lft = root->left;
            rgt = root->right;
            head->left = NULL;
        }
        
        else{
            head->right = root;
            lft = root->left;
            rgt = root->right;
            root->left = NULL;
            head = root;
        }
        
        getAns(lft, lft, rgt);    
        getAns(rgt, lft, rgt);
    }
    
    void flatten(TreeNode* root) {
        head = NULL;
        getAns(root, NULL, NULL);
    }
};



// GFG:
// Adding array elements:
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }
        
        while(pq.top() < k){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            ans++;
            
            pq.push(a + b);
        }
        
        return ans;
    }
};
