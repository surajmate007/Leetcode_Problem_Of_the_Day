class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        long long mod = 1e9+7;
        
        // hc.push_back(h); vc.push_back(w);
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        int n = hc.size(); int m = vc.size();
        
        long long maxh = hc[0]; long long maxv = vc[0];
        
        for(long long i=0; i<n-1; i++){
            maxh = (max(maxh, (long long)hc[i+1]-hc[i]))%mod;
        }
        for(long long i=0; i<m-1; i++){
            maxv = (max(maxv, (long long)vc[i+1]-vc[i]))%mod;
        }
        
        maxh = max(maxh, (long long)h-hc[n-1]);
        maxv = max(maxv, (long long)w-vc[m-1]);
        
        long long ans = (maxh * maxv)%mod;
        return ans;
    }
};
