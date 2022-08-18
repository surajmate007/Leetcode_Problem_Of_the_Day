// Leetcode Problem:

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for(auto e : mp){
            pq.push({e.second, e.first});
        }
        int cnt = 0; int ans = 0;
        
        while(cnt < n/2){
            cnt += pq.top().first;
            pq.pop();
            ans++;
        }
        
        return ans;
    }
};



// GFG Problem:

class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) { 
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0; int ans = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(mp.find(sum-k) != mp.end()){
                ans = max(ans, i-mp[sum-k]);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        return ans;
    } 
};
