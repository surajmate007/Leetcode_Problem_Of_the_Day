// Recursive:


class Solution {
public:
    
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int getAns(int n, int m, int i, int j, int moves){
        
        if(i>=n or j>=m or i<0 or j<0){
            return 1;
        }
        
        if(moves <= 0){
            return 0;
        }
        
        int ans = 0;
        
        for(auto d : dir){
            int x = i+d[0]; int y = j+d[1];
            ans += getAns(n, m, x, y, moves-1);
        }
        
        return ans;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return getAns(m, n, startRow, startColumn, maxMove);
    }
};


// Memoisation:


class Solution {
public:
    
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    long long mod = 1e9+7;
    
    int getAns(int n, int m, int i, int j, int moves, vector<vector<vector<int>>>& dp){
        
        if(i>=n or j>=m or i<0 or j<0){
            return 1;
        }
        
        if(moves <= 0){
            return 0;
        }
        
        if(dp[i][j][moves] != -1){
            return (dp[i][j][moves])%mod;
        }
        
        int ans = 0;
        
        for(auto d : dir){
            int x = i+d[0]; int y = j+d[1];
            ans = ans%mod + getAns(n, m, x, y, moves-1, dp)%mod;
        }
        
        return dp[i][j][moves] = ans%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>> (n+1, vector<int> (maxMove+1, -1))); 
        return getAns(m, n, startRow, startColumn, maxMove, dp);
    }
};
