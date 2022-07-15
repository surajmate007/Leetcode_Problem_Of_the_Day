class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    bool isValid(vector<vector<int>>& grid, int n, int m, int i, int j){
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j]==1){
            return true;
        }
        return false;
    }
    
    int dfs(vector<vector<int>>& grid, int n, int m, int i, int j){
        queue<pair<int, int>> q;
        q.push({i, j}); int cnt = 1;
        grid[i][j] = 0;

        while(!q.empty()){
            auto e = q.front(); q.pop();
            int x = e.first; int y = e.second;
            
            for(auto d : dir){
                if(isValid(grid, n, m, x+d[0], y+d[1])){
                    q.push({x+d[0], y+d[1]});
                    grid[x+d[0]][y+d[1]] = 0;
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    ans = max(ans, dfs(grid, n, m, i, j));
                }
            }
        }
        return ans;
    }
};
