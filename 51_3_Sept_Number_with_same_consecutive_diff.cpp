class Solution {
public:
    
    void getConsec(int n, int idx, int k, int& num, vector<int>& ans){
        if(idx >= n){
            ans.push_back(num);
            return; 
        }
        
        for(int i=0; i<10; i++){
            int val = num%10;
            if(abs(val - i) == k){
                num = num * 10 + i;
                getConsec(n, idx+1, k, num, ans);
                num = num/10;
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1; i<10; i++){
            getConsec(n, 1, k, i, ans);
        }
        return ans;
    }
};
