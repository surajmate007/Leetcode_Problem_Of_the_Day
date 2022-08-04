// here only odd and even matters:
// Divide p,q by 2 until at least one odd.

// If p = odd, q = even: return 0
// If p = even, q = odd: return 2
// If p = odd, q = odd: return 1
// I summary it as return 1 - p % 2 + q % 2


class Solution {
public:
    int mirrorReflection(int p, int q) {
        while (p % 2 == 0 && q % 2 == 0) p >>= 1, q >>= 1;
        return 1 - p % 2 + q % 2;
    }
};


// GFG:
// Check whether it is a complete binary tree:


class Solution{
public:    
    
    bool isCompleteBT(Node* root){
        queue<Node*> q;
        int marked = 0;
        q.push(root);
        
        while(!q.empty()){
            Node* nd = q.front(); q.pop();
                
            if(!nd->left){
                marked = 1;
            }
            else{
                if(marked == 1){
                    return false;
                }
                else{
                    q.push(nd->left);
                }
            }
                
            if(!nd->right){
                marked = 1;
            }
            else{
                if(marked == 1){
                    return false;
                }
                else{
                    q.push(nd->right);
                }
            }            
        }
        
        return true;
    }
};
