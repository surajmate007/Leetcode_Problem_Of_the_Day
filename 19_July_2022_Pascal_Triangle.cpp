class Solution {
public:
    
    long long nCr(int n, int r) {
    if(r > n - r) r = n - r;
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
    
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        
        for(int i=0; i<numRows; i++){
            vector<int> vec;
            for(int j=0; j<=i; j++){
                vec.push_back(nCr(i, j));
            }
            ans.push_back(vec);
        }
        
        return ans;
    }
};



// GFG 
// Ceil in BST:



int getAns(Node* root, int val, int& ans){
    if(root == NULL){
        if(ans != 0){
            return ans;
        }
        
        return -1;
    }
    
    if(root->data >= val){
        ans = root->data;
        return getAns(root->left, val, ans);
    }
    else{
        return getAns(root->right, val, ans);
    }
}

int findCeil(Node* root, int input) {
    int ans = 0;
    return getAns(root, input, ans);
}
