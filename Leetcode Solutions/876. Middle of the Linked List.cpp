class Solution {
public:
//TIME - O(N) SPACE - O(1)
    ListNode* middleNode(ListNode* head) {
        ListNode* first = head, *second = head;

        while(second && second->next){
            first = first->next;
            second = second->next->next;
        }

        return first;
    }
};