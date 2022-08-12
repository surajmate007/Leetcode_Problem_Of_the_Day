// Leetcode:
// Find LCA in BST

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
        
        else if((root->val > p->val and root->val < q->val) or (root->val < p->val and root->val > q->val)){
            return root;
        }
        
        else if(root->val > p->val and root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(root->val < p->val and root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        
        return root;
    }
};



// GFG:
// Case specific sorting of strings:

class Solution{
    public:
  
    string caseSort(string str, int n){
        vector<char> upper, lower, position;
        for(int i=0; i<n; i++){
            if(isupper(str[i])){
                upper.push_back(str[i]);
                position.push_back('u');
            }
            else{
                lower.push_back(str[i]);
                position.push_back('l');
            }
        }
        
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());
        
        string ans = "";
        int i=0; int j=0;
        for(int k=0; k<n; k++){
            if(position[k] == 'u'){
                ans += upper[i]; i++;
            }
            else{
                ans += lower[j]; j++;
            }
        }
        
        return ans;
    }
};
