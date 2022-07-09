// 10^5 size of array wass given.
// we can do one dimensional dp in O(n) but for 10^5 means such problems will be solved in O(nlogn) Thus here it is solved using dp + priority queue.

class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp = nums;
        priority_queue<pair<int, int>> pq;
        
        for(int i=n-1; i>=0; i--){
            while(!pq.empty() and pq.top().second > i+k){
                pq.pop();
            }
            
            if(!pq.empty()){
                dp[i] += pq.top().first;
            }
            
            pq.push({dp[i], i});
        }
        
        return dp[0];
    }
};
