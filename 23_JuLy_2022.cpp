//Leetcode:
// 315. Count of Smaller Numbers After Self.
// Same problem is repeated in GFG 2 days before.
// Solved usng merge sort.

class Solution {
public:
    
    void merge(vector<int>& count, vector<pair<int, int>>& nums, int left, int mid, int right){
        vector<pair<int, int>> temp (right-left+1);
        int i=left; int j=mid+1; int k=0;
        
        while(i <= mid and j <= right){
            if(nums[i].first <= nums[j].first){
                temp[k++] = nums[j++];
            }
            else{
                count[nums[i].second] += right-j+1;
                temp[k++] = nums[i++];
            }
        }
        
        while(i <= mid){
            temp[k++] = nums[i++];
        }
        
        while(j <= right){
            temp[k++] = nums[j++];
        }
        
        for(int i=left; i<=right; i++){
            nums[i] = temp[i-left];
        }
    }
    
    void mergeSort(vector<int>& count, vector<pair<int, int>>& nums, int left, int right){
        if(left < right){
            int mid = (left + (right-left)/2);
            mergeSort(count, nums, left, mid);
            mergeSort(count, nums, mid+1, right);
            merge(count, nums, left, mid, right);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({nums[i], i});
        }
        
        vector<int> count(n, 0);
        
        mergeSort(count, v, 0, n-1);
        
        return count;
    }
};




// GFG:
// Levels of Game:

// Using Recursion giving TLE:

class Solution{
    public:
        
        int getAns(int h, int m, int road){
            if(h<=0 or m<=0){
                return 0;
            }
            
            int x = 0, y=0;
            
            if(road == 1){
                x = 1 + getAns(h-5, m-10, 2);
                y = 1 + getAns(h-20, m+5, 3);
            }
            
            else if(road == 2){
                x = 1 + getAns(h+3, m+2, 1);
                y = 1 + getAns(h-20, m+5, 3);
            }
            
            else{
                x = 1 + getAns(h-5, m-10, 2);
                y = 1 + getAns(h+3, m+2, 1);
            }
            
            return max(x, y);
        }
        
        int maxLevel(int h,int m){
            return max({getAns(h, m, 1), getAns(h, m, 2), getAns(h, m, 3)})-1;
        }
};



// Optimised code using unordered_map:



class Solution{
    public:
        
        unordered_map<int,vector<int>> dp;
        int help(int prev,int h,int m){
           if(h<=0 || m<=0)
               return 0;
            
           if(dp.find(prev)!=dp.end()){
               vector<int> temp=dp[prev];
               return temp[2];
           }
           
           else{
               if(prev==1){
                   int y=1+help(2,h-5,m-10);
                   int z=1+help(3,h-20,m+5);
                   int ans=max(y,z);
                   dp[prev]={h,m,ans};
                   return ans;
               }
               
               else if(prev==2){
                   int x=1+help(1,h+3,m+2);
                   int z=1+help(3,h-20,m+5);
                   int ans=max(x,z);
                   dp[prev]={h,m,ans};
                   return ans;
                   
               }
               
               else if(prev==3){
                   int x=1+help(1,h+3,m+2);
                   int y=1+help(2,h-5,m-10);
                   int ans=max(x,y);
                   dp[prev]={h,m,ans};
                   return ans;
               }
           }
       }
       
       int maxLevel(int h,int m){
           dp.clear();
           return help(1,h+3,m+2);
       }
};
