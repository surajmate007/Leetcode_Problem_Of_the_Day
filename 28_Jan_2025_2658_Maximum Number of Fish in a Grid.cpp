class Solution {
public:
    vector<int> dirs = {0, 1, 0, -1, 0};

    int getAns(vector<vector<int>>& grid, int n, int m, int i, int j){
        int val = grid[i][j]; grid[i][j] = 0;
        int ans = val;
        for(int dir=0; dir<4; dir++){
            int ni = i+dirs[dir]; int nj = j+dirs[dir+1];
            if(ni<0 or nj<0 or ni>=n or nj>=m or grid[ni][nj]==0) continue;
            ans += getAns(grid, n, m, ni, nj);
        }
        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0) continue;
                ans = max(ans, getAns(grid, n, m, i, j));
            }
        }

        return ans;
    }
};
