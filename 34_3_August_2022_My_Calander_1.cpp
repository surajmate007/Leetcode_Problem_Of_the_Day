// Leetcode potd

class MyCalendar {
public:
    
    map<int,int>events;
    MyCalendar() {   
    }
    
    bool book(int start, int end) {
        auto next = events.upper_bound(start);
        if(next != events.end() &&   (*next).second < end)return false;
        events.insert({end,start});
        return true;
    }
    
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */





// Construct BST from preorder traversal.
class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    unordered_map<int, int> mp;
    int idx;
    
    Node* getTree(vector<int>& in, int lo, int hi){
        if(lo > hi){
            return NULL;
        }
        
        Node* nd;
        for(int i=lo; i<=hi; i++){
            if(mp[in[i]] == idx){
                nd = new Node();
                nd->data = in[i];
                idx++;
                nd->left = getTree(in, lo, i-1);
                nd->right = getTree(in, i+1, hi);
            }
        }
        
        return nd;
    }
    
    Node* post_order(int pre[], int n){
        vector<int> in;
        mp.clear();
        idx = 0;
        
        for(int i=0; i<n; i++){
            in.push_back(pre[i]);
            mp[pre[i]] = i;
        }
        
        sort(in.begin(), in.end());
        return getTree(in, 0, n-1);
    }
};
