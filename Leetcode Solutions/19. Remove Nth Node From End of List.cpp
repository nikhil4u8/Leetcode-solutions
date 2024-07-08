/*
Ques to ask :
    - If N > size of linked list?
    - If N == 0 then which node to remove?
    - Can N be negative?

Sol :
=> Two pass : [TIME - O(2*N) SPACE - O(1)]
    - Count total number of nodes in list, then we get position of last 
    nth node from starting (total nodes - N), so traverse that many steps 
    from forward direction & remove it.

BEST APPROACH 
=> One pass : [TIME - O(N) SPACE - O(1)]
    - Take 2 nodes seperated at n distance, so when last node reaches list 
    end then remove current node.
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head, *nth = head, *prev = NULL;
        
        //maintaing a difference of N among temp
        while(nth && n--) nth = nth->next;
        
        while(nth){
            nth = nth->next;
            prev = curr;
            curr = curr->next;
        }
        
        //removing curr node
        if(!prev) head = curr->next;
        else prev->next = curr->next;

        curr->next = NULL;
        return head;
    }
};