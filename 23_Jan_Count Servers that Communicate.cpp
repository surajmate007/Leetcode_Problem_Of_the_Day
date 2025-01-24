class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    bool found = false;
                    for(int ii=0; ii<n; ii++){
                        if(ii == i) continue;
                        if(grid[ii][j] == 1){
                            ans++; found = true; break;
                        }
                    }
                    if(!found){
                        for(int jj=0; jj<m; jj++){
                            if(jj == j) continue;
                            if(grid[i][jj] == 1){
                                ans++; found = true; break;
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};
