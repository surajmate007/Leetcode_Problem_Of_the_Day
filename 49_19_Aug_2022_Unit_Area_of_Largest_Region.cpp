class Solution{
    public:
    //Function to find unit area of the largest region of 1s.
    int dir[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {-1,1}, {1,-1}, {1,1}, {-1,-1}};
    
    int getAns(vector<vector<int>>& grid, int n, int m, int i, int j){
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;
        int ans = 1;
        
        while(!q.empty()){
            auto e = q.front(); q.pop();
            
            for(int k=0; k<8; k++){
                int x = e.first + dir[k][0]; int y = e.second + dir[k][1];
                if(x>=0 and y>=0 and x<n and y<m and grid[x][y] == 1){
                    q.push({x, y});
                    ans++;
                    grid[x][y] = 0;
                }
            }
        }
        
        return ans;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(); int m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    ans = max(ans, getAns(grid, n, m, i, j));
                }
            }
        }
        
        return ans;
    }
};
