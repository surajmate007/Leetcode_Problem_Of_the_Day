class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> ans;
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        unordered_map<int, pair<int, int>> mp;
        unordered_map<int, int> lowerMap;

        int i=0; int is = 0; int last = vec[0];
        while(i<n){
            while(i<n and vec[i] - last <= limit){
                lowerMap[vec[i]] = vec[is];
                last = vec[i];
                i++;
            }
            mp[vec[is]] = {is, i};
            is = i; 
            if(i<n) last = vec[i];
        }

        for(int i=0; i<n; i++){
            int val = lowerMap[nums[i]];
            pair<int, int> pr = mp[val];
            int idx = pr.first; int lim = pr.second;
            if(idx < lim){
                ans.push_back(vec[idx]);
                mp[val] = {idx+1, lim};
            }
        }

        return ans;
    }
};
