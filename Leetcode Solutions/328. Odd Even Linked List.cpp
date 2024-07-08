class Solution {
public:
    //TIME - O(N) SPACE - O(1)
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        
        ListNode* odd = head,*even = head->next,*one=head,*sec=head->next;
        
        while(even){
            odd->next = even->next;
            if(!odd->next) break;
            else odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        
        odd->next = sec;
        return one;
    }
};