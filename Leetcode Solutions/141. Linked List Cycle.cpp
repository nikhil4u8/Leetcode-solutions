/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //Approach 1 (time - O(n) space - O(n))
    //using hash-table to store previous elements and find if there exist any already visited element or not
    
    //Approach 2 (time - O(n) space - O(1))
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        
        ListNode* slow = head,*fast = head->next;
        
        while(slow!=fast){
            slow = slow->next;
            if(!fast || !fast->next) return false;
            fast = fast->next->next;
        }
        
        return true;
    }
};