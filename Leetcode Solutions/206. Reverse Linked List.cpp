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
    //ITERATIVE
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head,*prev=NULL,*next=NULL;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    //RECURSIVE
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        
        ListNode* res = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return res;
    }
};