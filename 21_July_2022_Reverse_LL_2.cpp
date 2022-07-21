// Leetcode:
// Reverse the LL between given indexes:

class Solution {
public:
    
    ListNode* reverse(ListNode* head, ListNode* prv){
        ListNode* curr = head; ListNode* nxt = NULL; ListNode* last = prv;
        while(curr != last){
            nxt = curr->next;
            curr->next = prv;
            prv = curr;
            curr = nxt;
        }
        
        return prv;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        while(right--){
            temp = temp->next;
        }
        
        if(left == 1){
            return reverse(head, temp);
        }
        
        else{
            ListNode* nd = head;
            left = left-2;
            while(nd->next and left--){
                nd = nd->next;
            }
            nd->next = reverse(nd->next, temp);
        }
        return head;
    }
};


// GFG:
// Get min at pop:  solved using 2 stacks

stack<pair<int, int>> global;

stack<int> _push(int arr[], int n){
    stack<int> st;
    for(int i=0; i<n; i++){
        st.push(arr[i]);
        if(global.empty() or arr[i] < global.top().first){
            global.push({arr[i], i});
        }
    }
    return st;
}

void _getMinAtPop(stack<int>st){
    int n = st.size()-1;
    while(n>=0){
        if(global.top().second == n){
            cout<<global.top().first<<" ";
            global.pop();
        }
        else{
            cout<<global.top().first<<" ";
        }
        n--;
    }
}

