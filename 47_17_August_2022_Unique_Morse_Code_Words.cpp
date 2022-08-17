// Leetcode:

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string arr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_map<string, int> mp;
        for(auto s : words){
            int n = s.length();
            string code = "";
            for(int i=0; i<n; i++){
                code += arr[s[i]-'a'];
            }
            mp[code]++;
        }
        
        return mp.size();
    }
};

// GFG:

class Solution {
public:
    vector<vector<int>> dir = {{1,2}, {2,1}, {1,-2}, {-2,1}, {-1,2}, {2,-1}, {-1,-2}, {-2,-1}};
    
	int minStepToReachTarget(vector<int>&knp, vector<int>&tgp, int n){
	    vector<vector<int>> vis(n, vector<int>(n, 0));
	    
	    queue<pair<int, int>> q;
	    q.push({knp[0]-1, knp[1]-1});
	    vis[knp[0]-1][knp[1]-1] = 1;
	    
	    if(knp[0] == tgp[0] and knp[1] == tgp[1]){
	        return 0;
	    }
	    
	    int ans = 0;
	    
	    while(!q.empty()){
	        int sz = q.size();
	        ans++;
	        while(sz--){
	            pair<int, int> pr = q.front();
    	        q.pop();
    	       
    	        for(int i=0; i<8; i++){
    	            int x = pr.first + dir[i][0]; int y = pr.second + dir[i][1];
    	            if(x>=0 and y>=0 and x<n and y<n and vis[x][y] == 0){
    	                vis[x][y] = 1;
    	                q.push({x, y});
    	                
    	                if(x==tgp[0]-1 and y==tgp[1]-1){
    	                    return ans;
    	                }
    	            }
    	        }
	        }
	    }
	    
	    return -1;
	}
};
