// Leetcode POTD:

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        int val = minutesToTest/minutesToDie;
                
        while(pow(val+1, pigs) < buckets){
            pigs++;
        }
        
        return pigs;
    }
};


// Quick Sort on DLL:


/*
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};
*/

class Solution{
public:
    
    Node* partition(Node *l, Node *h){
        Node *pivot=l;
        Node *left=l;
        Node *right=h;
        
        while(true){
            while(left!=NULL  &&  pivot->data>left->data){
                left=left->next;
            }
            
            while(right!=NULL  && pivot->data<=right->data && left!=right){
               right=right->prev;
            }
            
            if(left==right){
                return left;
            }
            
            swap(left->data,right->data);
        }
    }
};
