// DP based solution:

class Solution {
public:
    long long mod = 1e9+7;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        long long ans = 0;
        unordered_map<long long, long long> mp;
        
        for(int i=0; i<n; i++){
            long long cur_ans = 1;
            for(int j=0; j<i; j++){
                if(arr[i]%arr[j]){
                    continue;
                }
                long long val1 = arr[j];
                long long val2 = arr[i]/arr[j];
                cur_ans = (cur_ans + (mp[val1] * mp[val2])%mod)%mod;
            }
            
            mp[arr[i]] = cur_ans;
            ans = (ans + cur_ans)%mod;
        }
        
        return (int)ans;
    }
};


// GFG: using seive of erathonaes algorithm:
vector<int>prime;
    
    void prime_(long long N){
        long n = sqrt(N);
        // cout << n << " ";
        int ar[n+1] = {0};
        for(int i=2 ; i<=n ; i++)
        ar[i] = 1;
        
        for(int i=2 ; i*i<=n; i++){
            if(ar[i]){
                for(int j = 2*i ; j<=n; j+=i)
                ar[j] = 0;
            }
        }
        
        for(int i=2 ; i<=n; i++)
        {
            if(ar[i] == 1)
            prime.push_back(i);
        }
    }
    long long int nineDivisors(long long int N){
        //Code Here
        prime_(N);
        int ct = 0;
        for(long int i = 0 ; i<prime.size() ; i++){
            if((long)pow(prime[i] , 8) <= N)
            ct++;
            else
            break;
        }
        
        long long int i = 0;
        while(i<prime.size() ){
            int fl = 1;
            for(long long int j=i+1 ; j<prime.size() ; j++){
                if(pow(prime[i]*1LL*prime[j] , 2) <= N){
                    fl = 0;
                    ct++;
                }
                else
                break;
            }
            i++;
            if(fl)
            break;
        }
        return ct;
    }
