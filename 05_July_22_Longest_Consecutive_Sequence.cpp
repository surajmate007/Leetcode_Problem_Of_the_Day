class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp; int n = nums.size();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            mp[nums[i]] = 1;
        }
    
        for(int i=0; i<n; i++){
            if(mp.find(nums[i]-1) == mp.end()){
                int cnt = 1; int p = nums[i]+1;
                while(mp.find(p) != mp.end()){
                    cnt++; p++;
                }
                ans = max(ans, cnt);
            }
        }
        
        return ans;
    }
};
