class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        
        for(int i=1; i<n; i++){
            if(nums[i] > dp.back()){
                dp.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[idx] = nums[i];
            }
        }
        
        return dp.size();
    }
};


// Josephus Problem:

// brute force O(N*K)
class Solution{
    public:
    int josephus(int n, int k){
       queue<int> q;
       for(int i=1; i<=n; i++){
           q.push(i);
       }
       
       while(q.size() > 1){
           for(int i=0; i<k-1; i++){
               int a = q.front(); q.pop();
               q.push(a);
           }
           q.pop();
       }
       
       return q.front();
    }
};


// O(n) solution:

class Solution{
    public:
    int josephus(int n, int k){
        int prev =1;
        for(int i = 1;i<=n;i++)prev = (prev+k-1)%i+1;
        return prev;
    }
};


