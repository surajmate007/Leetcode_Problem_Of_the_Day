// Brute force:
// Leetcode:

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length();
        int m = words.size();
        int ans = 0;
        
        for(string word : words){
            int k = word.length();
            if(n < k){
                continue;
            }
            else{
                int i=0; int j=0;
                while(j<k and i<n){
                    if(s[i] == word[j]){
                        i++; j++;
                    }
                    else{
                        i++;
                    }
                }
                
                if(j==k){
                    ans++;
                }
            }
        }
        return ans;
    }
};




// GFG:



// Find minimum number of insertions to make a string palindrome.
// here we will first find the lps of the string and then we will subtract the length of lps from the lwngth of the string..



class Solution{
  public:
    
    int findLps(string s1, string s2, int n){
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(i==0 or j==0){
                    dp[i][j] = 0;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][n];
    }
    
    
    int countMin(string str){
        int n = str.length();
        string rev = str;
        reverse(rev.begin(), rev.end());
        int lps = findLps(str, rev, n);
        
        return n-lps;
    }
};



