class Solution {
public:
    
    bool isInterleave(string s1, string s2, string s3) {
        stack<vector<int>> st;
        int n3 = s3.length(); int n1 = s1.length(); int n2 = s2.length();
        
        if(n3 != n1 + n2){
            return false;
        }
        
        int i=0; int j=0; int k=0;
        s1.push_back('?');
        s2.push_back('?');
        
        while(k<n3){
            if(s3[k] == s1[i] and s3[k] == s2[j]){
                st.push({i, j ,k});
                // cout<<"pushed in stack..."<<endl;
                k++; i++;
            }
            else{
                if(s3[k] == s1[i]){
                    k++; i++;
                }
                else if(s3[k] == s2[j]){
                    k++; j++;
                }
                else{
                    if(st.empty()){
                        return false;
                    }
                    else{
                        // cout<<"Poped out of stack..."<<endl;
                        i = st.top()[0]; j=st.top()[1]; k = st.top()[2];
                        // cout<<i<<" "<<j<<" "<<k<<endl;
                        st.pop();
                        k++; j++;
                    }
                }
            }
            
            // cout<<i<<" "<<j<<" "<<k<<endl;
        }
        
        if(k==n3 and i==n1 and j==n2){
            return true;
        }
        
        return false;
    }
};


// recursive approach with memoization:

class Solution {
public:
    bool getAns(string s1, int i, string s2, int j, string s3, int k, vector<vector<int>>& dp){
        if(i==s1.length()){
            return s2.substr(j) == s3.substr(k);
        }
        
        if(j==s2.length()){
            return s1.substr(i) == s3.substr(k);
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        bool ans = false;
        if((s1[i] == s3[k] and getAns(s1, i+1, s2, j, s3, k+1, dp)) or (s2[j] == s3[k] and getAns(s1, i, s2, j+1, s3, k+1, dp))){
            ans = true;
        }
        
        dp[i][j] = ans;
        return ans;
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(); int n2 = s2.length(); int n3 = s3.length();
        if(n1+n2 != n3){
            return false;
        }
        
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return getAns(s1, 0, s2, 0, s3, 0, dp);
    }
};
