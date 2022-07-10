class Solution {
public:
    // write recursive code which can return int:
    
    int getAns(vector<int>& cost, int idx){
        int ans = 0;

        if(idx >= cost.size()){
            return ans;
        }

        ans = min(getAns(cost, idx+1), getAns(cost, idx+2)) + cost[idx];
        return ans;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
       return min(getAns(cost, 0), getAns(cost, 1));
    }
};


// Memoised:


class Solution {
public:
    // write recursive code which can return int:
    
    int getAns(vector<int>& cost, int idx, vector<int>& dp){
        int ans = 0;

        if(idx >= cost.size()){
            return ans;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }

        ans = min(getAns(cost, idx+1, dp), getAns(cost, idx+2, dp)) + cost[idx];
        return dp[idx] = ans;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(getAns(cost, 0, dp), getAns(cost, 1, dp));
    }
};
