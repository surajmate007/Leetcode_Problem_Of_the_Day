// Leetcode:
// Valid Anagram:


class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);
        if(s.length() != t.length()){
            return false;
        }
        
        for(int i=0; i<s.length(); i++){
            freq[s[i]-'a']++;
        }
        
        for(int i=0; i<s.length(); i++){
            freq[t[i]-'a']--;
        }
        
        for(int i=0; i<26; i++){
            if(freq[i] != 0){
                return false;
            }
        }
        
        return true;
    }
};





// GFG:
// Geek and Knots:
// using nCr

class Solution{
public:
    
    long long mod = 1e9+7;
    
    int nCr(int n, int r) {
        vector<vector<int>> memo(n+1, vector<int> (r+1, 0));
        
        if (n < r) return 0;
    
        for (int j = 0;j < r + 1;j++) {
            memo[0][j] = 0;
        }
        
        for (int i = 0;i < n + 1;i++) {
            memo[i][0] = 1;
        }
    
        for (int i = 1;i < n + 1;i++) {
            for (int j = 1;j <= min(i, r);j++) {
                memo[i][j] = (memo[i - 1][j - 1]%mod + memo[i - 1][j]%mod)%mod;
            }
        }
        
        return memo[n][r];
    }
    

    int knots(int M, int N, int K){
        int way1 = nCr(M, K)%mod;
        int way2 = nCr(N, K)%mod;
        return (way1%mod * way2%mod)%mod;
    }
};
