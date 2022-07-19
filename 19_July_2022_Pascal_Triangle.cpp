class Solution {
public:
    
    long long nCr(int n, int r) {
    if(r > n - r) r = n - r;
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
    
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        
        for(int i=0; i<numRows; i++){
            vector<int> vec;
            for(int j=0; j<=i; j++){
                vec.push_back(nCr(i, j));
            }
            ans.push_back(vec);
        }
        
        return ans;
    }
};
