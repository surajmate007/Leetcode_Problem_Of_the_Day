class Solution {
public:
    vector<vector<int>> vec;
    bool isPresent(int node, int target, vector<int>& vis){
        vis[node] = 1;

        vector<int> neigh = vec[node];
        for(int i=0; i<neigh.size(); i++){
            int v = neigh[i];
            if(vis[v] == 1) continue;
            if(v == target) return true;
            if(isPresent(v, target, vis)) return true;
        }

        return false;
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        vec.resize(n);
        for(auto e : prereq){
            int u = e[0]; int v = e[1];
            vec[u].push_back(v);
        }

        vector<bool> ans;
        for(auto e : queries){
            vector<int> vis(n, 0);
            ans.push_back(isPresent(e[0], e[1], vis));
            vis.clear();
        }

        return ans;
    }
};
