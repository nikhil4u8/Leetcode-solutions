/*
Desc : Reverse linked list from left to right
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head,*prev=NULL,*next=NULL;
        
        left--;
        right -= left;
        
        while(left--){
            prev = curr;
            curr = curr->next;
        }
        
        ListNode* root = prev;
        ListNode* root1 = curr;
        
        while(right--){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        root1->next = curr;
        if(root) root->next = prev;
        else head = prev;
        
        return head;
    }
};