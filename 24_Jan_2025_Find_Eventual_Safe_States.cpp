class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> vec(n);
        vector<int> vis(n, 0);
        vector<int> ans;
        queue<int> q;

        for(int i=0; i<n; i++){
            vector<int> temp = graph[i];
            int m = temp.size();
            if(m == 0){
                q.push(i); vis[i] = 1; ans.push_back(i); continue;
            }
            for(int j=0; j<m; j++){
                if(temp[j] == i) continue;
                vec[temp[j]].push_back(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            int m = vec[node].size();
            for(int j=0; j<m; j++){
                int nn = vec[node][j];
                if(vis[nn] == 1) continue;
                bool flag = true;
                for(int k=0; k<graph[nn].size(); k++){
                    if(vis[graph[nn][k]] == 0){
                        flag = false; break;
                    }
                }
                if(!flag) continue;
                q.push(vec[node][j]); vis[vec[node][j]] = 1;
                ans.push_back(vec[node][j]);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};



// can also solve it using outdegree of the nodes.

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> vec(n);
        vector<int> vis(n, 0);
        vector<int> outDegree(n, 0);
        vector<int> ans;
        queue<int> q;

        for(int i=0; i<n; i++){
            vector<int> temp = graph[i];
            int m = temp.size();
            outDegree[i] = m;
            if(m == 0){
                q.push(i); vis[i] = 1; ans.push_back(i); continue;
            }
            for(int j=0; j<m; j++){
                if(temp[j] == i) continue;
                vec[temp[j]].push_back(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            int m = vec[node].size();
            for(int j=0; j<m; j++){
                int nn = vec[node][j];
                if(vis[nn] == 1) continue;
                outDegree[nn]--;
                if(outDegree[nn] > 0) continue;
                q.push(vec[node][j]); vis[vec[node][j]] = 1;
                ans.push_back(vec[node][j]);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
