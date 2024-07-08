//TIME - O(N) SPACE - O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;

        ListNode* first = head, *second = head->next, *prev = NULL;

        while(first && second){
            first->next = second->next;
            second->next = first;
            if(!prev) head = second;
            else prev->next = second;

            prev = first;
            if(!first->next) break;
            first = first->next;

            if(!first->next) break;
            second = first->next;
        }        

        return head;
    }
};