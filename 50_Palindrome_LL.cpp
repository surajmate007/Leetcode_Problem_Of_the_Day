// Leetcode:

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
    
    ListNode* getMid(ListNode* head){
        ListNode* slow = head; ListNode* fast = head;
        while(slow and fast and fast->next){
            slow = slow->next; fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL; ListNode* next = NULL;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* mid = getMid(head);
        ListNode* nmid = reverse(mid);
        
        while(nmid != NULL){
            if(head->val != nmid->val){
                return false;
            }
            head = head->next; nmid = nmid->next;
        }
        
        return true;
    }
};



// GFG:


bool getAns(Node* root1, Node* root2){
    if(root1==NULL and root2==NULL){
        return true;
    }
    if(root1==NULL or root2==NULL){
        return false;
    }
    
    bool ans1 = getAns(root1->left, root2->right);
    bool ans2 = getAns(root1->right, root2->left);
    
    return ans1 and ans2;
}

bool IsFoldable(Node* root){
    if(root == NULL){
        return true;
    }
    
    return getAns(root->left, root->right);
}
