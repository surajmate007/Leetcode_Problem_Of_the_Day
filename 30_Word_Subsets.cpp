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



// 29 July GFG


class Solution{   
public:
    bool isPrime(int n)
    {
        for(int i = 2;i*i<=n;i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }

    int firingEmployees(vector<int> &arr, int n){
        vector<int> adjList[n+1];
        for(int i = 0;i<n; i++){
            adjList[arr[i]].push_back(i+1);
        }
        
        queue<pair<int,int>> Q;
        int startNode = adjList[0][0];
        Q.push({startNode, 0});
        int cnt = 0;
        vector<int> visited(n+1, 0);
        visited[startNode]=1;
        while(!Q.empty())
        {
            pair<int,int> front = Q.front();
            Q.pop();
            int node = front.first;
            int level = front.second;
            if(node!=startNode)
            {
                if(isPrime(node+level)) cnt++;
            }
            
            for(int i = 0;i<adjList[node].size();i++)
            {
                if(!visited[adjList[node][i]])
                {
                    visited[adjList[node][i]]=1;
                    Q.push({adjList[node][i], level+1});
                }
            }
        }
        return cnt;
    }
};


// GFG 30 JULY:

class Solution{
  public:
  
    char firstRep (string s){
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        
        for(int i=0; i<s.length(); i++){
            if(mp[s[i]] > 1){
                return s[i];
            }
        }
        
        return '#';
    }
};
