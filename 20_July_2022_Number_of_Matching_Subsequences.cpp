// Brute force:


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



// Optimised:



