class Solution {
public:
    //Time - O(NlogN)  Space - O(logN) ->recursive stack, since maximum depth of recursion tree is logN
    //At each level, we merge n nodes which takes O(N) time
    //So the time complexity for split and merge operation is O(nlogn)
    ListNode* merge_list(ListNode* a,ListNode* b){
        if(!a && !b) return NULL;
        if(!a) return b;
        if(!b) return a;
        
        if(a->val>=b->val){
            b->next = merge_list(a,b->next);
            return b;
        }
        
        a->next = merge_list(a->next,b);
        return a;
    }
    void split_list(ListNode* head,ListNode* &a,ListNode* &b){
        if(!head) return;
        ListNode* mid=head,*mid_next=head;
        
        while(mid_next->next && mid_next->next->next){
            mid = mid->next;
            mid_next = mid_next->next->next;
        }
        
        a=head;
        b=mid->next;
        
        mid->next = NULL;
    }
    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        
        ListNode* a=NULL,*b=NULL;
        
        split_list(head,a,b);
        
        a = sortList(a);
        b = sortList(b);
        
        return merge_list(a,b);
    }
};