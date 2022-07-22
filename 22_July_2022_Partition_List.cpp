// Leetcode POTD:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        vector<int> smaller, bigger;
        
        while(temp){
            if(temp->val >= x){
                bigger.push_back(temp->val);
            }
            else{
                smaller.push_back(temp->val);
            }
            temp = temp->next;
        }
        
        for(int i=0; i<bigger.size(); i++){
            smaller.push_back(bigger[i]);
        }
        
        temp = head;
        int i=0;
        
        while(temp){
            temp->val = smaller[i];
            temp = temp->next;
            i++;
        }
        
        return head;
    }
};



// GFG POTD:
// It was just to find the number of disconnected components.

class Solution {
  public:
  
    void getProveince(vector<int> adj[], int p, vector<int>& visited){
        queue<int> q;
        q.push(p);
        
        while(!q.empty()){
            int t = q.front();
            q.pop();
            
            visited[t] = 1;
            for(auto e : adj[t]){
                if(visited[e] == 0){
                    q.push(e);
                }
            }
        }
        return;
    }
  
    int numProvinces(vector<vector<int>> arr, int n) {
        vector<int> adj[n];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j] == 1 and i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n, 0);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                getProveince(adj, i, visited);
                ans++;
            }
        }
        
        return ans;
    }
};
