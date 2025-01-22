class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(); int m = isWater[0].size();
        vector<int> dirs = {0, 1, 0, -1, 0};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j] == 1){
                    pq.push({0, i, j});
                    isWater[i][j] = 0;
                }
                else isWater[i][j] = INT_MAX;
            }
        }

        while(!pq.empty()){
            vector<int> vec = pq.top(); pq.pop();
            int ht = vec[0]; int i = vec[1]; int j = vec[2];
            for(int k=0; k<4; k++){
                int ni = i+dirs[k]; int nj = j+dirs[k+1];
                if(ni<0 or nj<0 or ni>=n or nj>=m) continue;
                if(isWater[ni][nj] > ht+1){
                    pq.push({ht+1, ni, nj});
                    isWater[ni][nj] = ht+1;
                }
            }
        }

        return isWater;
    }
};
