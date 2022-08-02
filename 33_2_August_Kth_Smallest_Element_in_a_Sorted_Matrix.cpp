class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int ans = 0;
        int lo = matrix[0][0]; int hi = matrix[n-1][n-1];
        
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            int cnt = 0;
            
            for(int i=0; i<n; i++){
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            
            if(cnt < k){
                lo = mid + 1;
            }  
            else{
                ans = mid;
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};


// GFG
// Delete Node Greater than k:


class Solution{
  public:
    
    Node* deleteNode(Node* root, int k){
        if(root == NULL){
            return NULL;
        }
        
        if(root->data >= k){
            root = deleteNode(root->left, k);
        }
        
        else{
            root->right = deleteNode(root->right, k);
        }
        
        return root;
    }
};
