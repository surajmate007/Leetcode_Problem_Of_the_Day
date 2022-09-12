// simple greedy approach using 2 pointers.

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int i=0; int j=n-1; int score = 0;
        int ans = 0;
        
        while(i<=j){
            if(power < tokens[i]){
                if(score > 0){
                    score--;
                    power += tokens[j];
                    j--;
                }
                else{
                    break;
                }
            }
            
            else{
                power -= tokens[i];
                score++; i++;
            }
            
            ans = max(ans, score);
        }
        
        return ans;
    }
};
