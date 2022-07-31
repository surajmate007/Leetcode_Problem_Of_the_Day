class Solution{
	public:
	
	bool check_elements(int arr[], int n, int A, int B){
		unordered_set<int> st;
		for(int i=0; i<n; i++){
		    st.insert(arr[i]);
		}
		
		for(int i=A; i<=B; i++){
		    if(st.count(i) == 0){
		        return false;
		    }
		}
		
		return true;
	}
  
};
	
