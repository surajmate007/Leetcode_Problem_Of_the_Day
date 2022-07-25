// GFG POTD:
// Max sum leaf to root path:


class Solution{
    public:
    
    int getAns(Node* root){
        if(root == NULL){
            return 0;
        }
        
        int l = getAns(root->left);
        int r = getAns(root->right);
        
        int sum = root->data + max(l, r);
        
        return sum;
    }
    
    int maxPathSum(Node* root){
        return getAns(root);
    }
};
