// Leetcode:
// Find First and Last Position of Element in Sorted Array


class Solution {
public:
    
    int upper_bound(vector<int> nums, int target){
        int lo = 0; int hi = nums.size()-1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(nums[mid] > target){
                hi = mid - 1; 
            }
            else{
                lo = mid + 1;
            }
        }
        
        return lo-1;
    }
    
    int lower_bound(vector<int> nums, int target){
        int lo = 0; int hi = nums.size()-1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(nums[mid] < target){
                lo = mid + 1; 
            }
            else{
                hi = mid - 1;
            }
        }
        
        return hi+1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums, target);
        int last = upper_bound(nums, target);
        
        if(first > last){
            return {-1, -1};
        }
        return {first, last};
    }
};



// GFG:

// BellmanFord without using structure:
// Here it is already told that the graph will not have negative cycles hence we dont need to check it by using one extra loop.


class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        int n = adj.size();
        
        for(int i=0; i<V-1; i++){
            for(int j=0; j<n; j++){
                vector<int> e = adj[j];
                int s = e[0]; int d = e[1]; int w = e[2];
                if(dist[s] != 1e8){
                    if(dist[s] + w < dist[d]){
                        dist[d] = dist[s] + w;
                    }
                }
            }
        }
        
        return dist;
    }
};
