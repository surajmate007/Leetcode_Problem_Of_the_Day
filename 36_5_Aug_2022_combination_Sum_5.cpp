// This is the recursive code:

class Solution {
public:
    
    int getAns(vector<int>& nums, int n, int target){
        if(target == 0){
            return 1;
        }
        int ans = 0;
        
        for(int i=0; i<n; i++){
            if(nums[i] <= target){
                ans += getAns(nums, n, target-nums[i]);
            }
        }
        
        return ans;
    }
    
    int combinationSum4(vector<int>& nums, int target){
        int n = nums.size();
        return getAns(nums, n,target);
    }
};

// Memoised:
// 100% faster
class Solution {
public:
    
    int getAns(vector<int>& nums, int n, int target, vector<int>& dp){
        if(target == 0){
            return 1;
        }
        
        if(dp[target] != -1){
            return dp[target];
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            if(nums[i] <= target){
                ans += getAns(nums, n, target-nums[i], dp);
            }
        }
        
        return dp[target] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target){
        int n = nums.size();
        vector<int> dp(target+1, -1);
        return getAns(nums, n, target, dp);
    }
};

// X Total Shapes:

class Solution{
    public:
    //Function to find the number of 'X' total shapes.
    
    int d1[4] = {0, 1, 0, -1};
    int d2[4] = {1, 0, -1, 0};
    
    void getAns(vector<vector<char>>& grid, int n, int m, int i, int j){
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 'O';
        
        while(!q.empty()){
            auto e = q.front(); q.pop();
            
            
            for(int i=0; i<4; i++){
                int x = e.first + d1[i];
                int y = e.second + d2[i];
                if(x>=0 and y>=0 and x<n and y<m and grid[x][y] == 'X'){
                    grid[x][y] = 'O';
                    q.push({x, y});
                }
            }
        }
    }
    
    int xShape(vector<vector<char>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'X'){
                    ans++;
                    getAns(grid, n, m, i, j);
                }
            }
        }
        
        return ans;
    }
};
