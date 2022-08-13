// Leetcode:
// String concatenation:

class Solution{
    
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        int n=words.size();
        int m=words[0].size();
        int total=n*m;
        if(s.size()<total){
            return ans;
        }
        
        for(int i=0;i<=s.size()-total;i++){
            unordered_map<string,int>mp;
            
            for(int j=0; j<n; j++){
                mp[words[j]]++;
            }
            
            int k;
            for(k=0; k<n; k++){
                string temp=s.substr(i+k*m,m);
                if(mp.count(temp)==0){
                    break;
                }
                else{
                    if(mp[temp]!=0){
                        mp[temp]--;
                    }
                    else{
                        break;
                    }
                }
            }
            if(k==n){
                ans.push_back(i);
            }
        }
        
        return ans ;
    }
};



// Max length chain:
// GFG:

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    /*You are required to complete this method*/
    
    static bool comp(struct val a, struct val b){
        return a.second < b.second;
    }
    
    int maxChainLen(struct val p[],int n){
        sort(p, p+n, comp);
        int last = p[0].second;
        int ans = 1;
        
        for(int i=1; i<n; i++){
            if(p[i].first > last){
                ans++;
                last = p[i].second;
            }
        }
        
        return ans;
    }
};
