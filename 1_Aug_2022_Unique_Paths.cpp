// Leetcode POTD:

class Solution {
public:

    int getAns(int n, int m, int i, int j, vector<vector<int>>& dp){
        if(i>=n  or i<0 or j>=m or j<0){
            return 0;
        }
        
        if(i==n-1 and j==m-1){
            return 1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        return dp[i][j] = getAns(n, m, i+1, j, dp) + getAns(n, m, i, j+1, );
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return getAns(m, n, 0, 0, dp);
    }
};


// GFG POTD:
// Egg Dropping Problem:

class Solution{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int eggDrop(int n, int f) {
        if(n==1 or f==0 or f==1){
            return f;
        }
        
        int ans = INT_MAX;
        for(int k=1; k<=f; k++){
            int temp = 1 + max(eggDrop(n-1, k-1), eggDrop(n, f-k));
            ans = min(ans, temp);
        }
        
        return ans;
    }
};


// Memoised:

class Solution{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int getAns(int n, int f, vector<vector<int>>& dp){
        if(n==1 or f==0 or f==1){
            return f;
        }
        
        if(dp[n][f] != -1){
            return dp[n][f];
        }
        
        int ans = INT_MAX;
        for(int k=1; k<=f; k++){
            int temp = 1 + max(getAns(n-1, k-1, dp), getAns(n, f-k, dp));
            ans = min(ans, temp);
        }
        
        return dp[n][f] = ans;
    }
    
    int eggDrop(int n, int f) {
        vector<vector<int>> dp(n+1, vector<int> (f+1, -1));
        return getAns(n, f, dp);
    }
};
