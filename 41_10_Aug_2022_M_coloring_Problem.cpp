// GFG M coloring problem:

class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isPossible(bool graph[101][101], vector<int>& colors, int n, int nd, int c){
        for(int k=0; k<n; k++){
            if(graph[k][nd] == 1){
                if(colors[k] == c){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool getAns(bool graph[101][101], vector<int>& colors, int m, int n){
        for(int i=0; i<n; i++){
            if(colors[i] == -1){
                for(int c=1; c<=m; c++){
                    if(isPossible(graph, colors, n, i, c)){
                        colors[i] = c;
                        if(getAns(graph, colors, m, n) == true){
                            return true;
                        }
                        colors[i] = -1;
                    }
                }
                return false;
            }
        }
        return true;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> colors(n, -1);
        return getAns(graph, colors, m, n);
    }
};


// Leetcode:
// Generate binary search tree from sorted array:


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
    
    TreeNode* formTree(vector<int>& nums, int left, int right){
        if(left > right){
            return NULL;
        }
        
        int mid = left + (right-left)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = formTree(nums, left, mid-1);
        node->right = formTree(nums, mid+1, right);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }
        
        return formTree(nums, 0, nums.size()-1);
    }
};
