class Solution {
public:
    int maximumInvitations(vector<int>& nums) {
        int n = nums.size();
        vector<int> indegree(n, 0), depth(n, 1);

        for(int i=0; i<n; i++) indegree[nums[i]]++;
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front(); q.pop();
            int next = nums[node];
            depth[next] = max(depth[next], depth[node]+1);
            indegree[next]--;
            if(indegree[next] == 0) q.push(next);
        }
        int longestCycle = 0; int twoCycle = 0;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) continue;
            int cycleLength = 0; int curr = i;
            while(indegree[curr] != 0){
                indegree[curr] = 0;
                cycleLength++; curr = nums[curr];
            }

            if(cycleLength == 2){
                twoCycle += (depth[i] + depth[nums[i]]);
            }
            else{
                longestCycle = max(longestCycle, cycleLength);
            }
        }

        return max(longestCycle, twoCycle);
    }
};
