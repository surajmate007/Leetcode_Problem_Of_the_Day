// simple solution:

class Solution{
  public:
    // function should return the number of turns required to go from first node to second node
    Node* getLCA(Node* root, int f, int s){
        if(root == NULL){
            return root;
        }
        
        if(root->data == f or root->data == s){
            return root;
        }
        
        Node* left = getLCA(root->left, f, s);
        Node* right = getLCA(root->right, f, s);
        
        if(left and right){
            return root;
        }
        
        if(!left){
            return right;
        }
        
        return left;
    }
    
    int countTurns(string ds){
        int ans = 0; char last = ds[0];
        for(int i=1; i<ds.size(); i++){
            if(ds[i] != last){
                ans++;
                last = ds[i];
            }
        }
        
        return ans;
    }
    
    int getTurns(Node* root, int val, string ds){
        if(root == NULL){
            return -1;
        }
        
        if(root->data == val){
            // cout<<ds<<endl;
            return countTurns(ds);
        }
        
        int left = getTurns(root->left, val, ds+'L');
        int right = getTurns(root->right, val, ds+'R');
        
        if(left != -1){
            return left;
        }
        else{
            return right;
        }
    }
    
    int NumberOFTurns(struct Node* root, int first, int second){
        Node* lca = getLCA(root, first, second);
        
        int ans = -1;
        if(lca->data == first){
            ans = getTurns(lca, second, "");
        }
        
        else if(lca->data == second){
            ans = getTurns(lca, first, "");
        }
        
        else{
            ans = getTurns(lca, first, "") + getTurns(lca, second, "") + 1;
        }
        
        if(ans == 0){
            return -1;
        }
        
        return ans;
    }
};
