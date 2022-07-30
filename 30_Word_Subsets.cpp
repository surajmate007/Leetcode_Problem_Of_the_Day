class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        unordered_map<string, unordered_map<char, int>> mp1, mp2;
        for(auto s : words1){
            for(int i=0; i<s.length(); i++){
                mp1[s][s[i]]++;
            }
        }
        
        for(auto s : words2){
            if(mp2.find(s) == mp2.end()){
                for(int i=0; i<s.length(); i++){
                    mp2[s][s[i]]++;
                }
            }
        }
        
        unordered_map<char, int> mp;
        
        for(auto e : mp2){
            for(auto k : e.second){
                if(mp.find(k.first) == mp.end()){
                    mp[k.first] = k.second;
                }
                else{
                    mp[k.first] = max(mp[k.first], k.second);
                }
            }
        }
        
        for(auto x : mp1){
            bool flag = true;
            for(auto y : mp){
                if(x.second[y.first] < y.second){
                    flag = false;
                    break;
                }
            }
            
            if(flag){
                ans.push_back(x.first);
            }
        }
        
        return ans;
    }
};
