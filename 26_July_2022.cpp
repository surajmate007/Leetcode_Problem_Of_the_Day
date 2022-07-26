// Leetcode: Lowest_Common_Ancestor_of_Binary_Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        
        if(root == p or root == q){
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(right and left){
            return root;
        }
        
        if(!right){
            return left;
        }
        if(!left){
            return right;
        }
        
        return NULL;
    }
};



// GFG POTD:
// Find longest palindrome in linkedlist

#include<bits/stdc++.h>
/* The Node is defined 
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*The function below returns an int denoting
the length of the longest palindrome list. */

int getLongest(vector<int> vec, int n, int lo, int hi){
    while(lo >=0  and hi < n){
        if(vec[lo] == vec[hi]){
            lo--; hi++;
        }
        else{
            break;
        }
    }
    
    return hi - lo - 1;
}

vector<int> listtoArray(Node* head){
    vector<int> vec;
    
    while(head){
        vec.push_back(head->data);
        head = head ->next;
    }
    
    return vec;
}

int maxPalindrome(Node *head){
    vector<int> vec = listtoArray(head);
    int n = vec.size();
    int ans = 0;
    
    
    for(int i=0; i<n; i++){
        int lo = i-1; int hi = i+1;
        ans = max(ans, getLongest(vec, n, lo, hi));
        lo = i;
        ans = max(ans, getLongest(vec, n, lo, hi));
    }
    
    return ans;
}
