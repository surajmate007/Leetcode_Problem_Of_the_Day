// Recursive:


class Solution {
public:
    
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int getAns(int n, int m, int i, int j, int moves){
        
        if(i>=n or j>=m or i<0 or j<0){
            return 1;
        }
        
        if(moves <= 0){
            return 0;
        }
        
        int ans = 0;
        
        for(auto d : dir){
            int x = i+d[0]; int y = j+d[1];
            ans += getAns(n, m, x, y, moves-1);
        }
        
        return ans;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return getAns(m, n, startRow, startColumn, maxMove);
    }
};


// Memoisation:


class Solution {
public:
    
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    long long mod = 1e9+7;
    
    int getAns(int n, int m, int i, int j, int moves, vector<vector<vector<int>>>& dp){
        
        if(i>=n or j>=m or i<0 or j<0){
            return 1;
        }
        
        if(moves <= 0){
            return 0;
        }
        
        if(dp[i][j][moves] != -1){
            return (dp[i][j][moves])%mod;
        }
        
        int ans = 0;
        
        for(auto d : dir){
            int x = i+d[0]; int y = j+d[1];
            ans = ans%mod + getAns(n, m, x, y, moves-1, dp)%mod;
        }
        
        return dp[i][j][moves] = ans%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>> (n+1, vector<int> (maxMove+1, -1))); 
        return getAns(m, n, startRow, startColumn, maxMove, dp);
    }
};



// GFG potd:
// find smaller elemnets on the right of each element in the array.


class Solution{
public:
    
    void merge(vector<int> &count,vector<pair<int,int>> &v,int left ,int mid,int right){
        
        vector<pair<int,int>> temp(right-left+1);
        int i=left;
        int j=mid+1;
        int k=0;
        
        while(i<=mid && j<=right){
            
            if(v[i].first <= v[j].first){
                temp[k++] = v[j++];
            }
            else{
                count[v[i].second] += right-j+1;
                temp[k++]=v[i++];
            }
        }
        
        while(i<=mid){
            temp[k++]=v[i++]; 
        }
        while(j<=right){
            temp[k++]=v[j++];
        }
        for(int i=left;i<=right;i++){
            v[i]=temp[i-left];
        }
    }
    
    void mergeSort(vector<int> &count,vector<pair<int,int>> &v,int left,int right){
        
        if(left<right){
            int mid=left + (right-left)/2;
            mergeSort(count,v,left,mid);
            mergeSort(count,v,mid+1,right);
            merge(count,v,left,mid,right);
        }
    }


	vector<int> constructLowerArray(int *arr, int n) {
	    
	    vector<pair<int,int>>v(n);
	    
	    for(int i=0;i<n;i++){
	        pair<int,int>p;
	        p.first=arr[i];
	        p.second=i;
	        v[i]=p;
	    }
	    
	    vector<int>count(n,0);
	    
	    mergeSort(count,v,0,n-1);
	    
	    return count;
	    
	}
};
