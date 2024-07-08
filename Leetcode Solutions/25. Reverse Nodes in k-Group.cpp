**FOLLOW-UP
    1.Reverse K alternate nodes
class Solution {
public:
    //RECURSION
    //TIME - O(N)->traversing the list only once  SPACE - O(N/K)-> we 
    //process k nodes and then make recursive call, so total recursive 
    //call could be N/K
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        
        int count = 0;
        ListNode* curr = head,*prev=head,*next=NULL;
        
        while(curr && count<k){
            curr = curr->next;
            count++;
        }
        
        curr = head;
        if(count==k){
            int grp = k;
            ListNode* temp = curr;
            
            while(grp--){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            temp->next = reverseKGroup(curr,k);
        }
        
        return prev;
    }
    //ITERATIVE
    //TIME - O(N)  SPACE - O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* curr = head,*prev=NULL,*next=NULL,*last=NULL,*start=NULL,*root=NULL;
        
        while(curr){
            curr = curr->next;
            count++;
        }
        
        curr = head;
        int grp = count/k;
        
        while(grp--){
            int temp = k;
            start = curr;
            while(temp--){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            if(!root) root = prev;
            if(last) last->next = prev;
            last = start;
            prev = NULL;
        }
        
        last->next = curr;
        
        return root;
    }
};

1.K alternate reverse
ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* curr = head,*prev=NULL,*next=NULL,*last=NULL,*start=NULL,*root=NULL;
        
        while(curr){
            curr = curr->next;
            count++;
        }
        
        curr = head;
        int grp = count/(2*k);
        
        while(grp--){
            int temp = k;
            start = curr;
            while(temp--){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            start->next = curr;
            if(!root) root = prev;
            if(last) last->next = prev;
            temp=K;
            while(temp--){
                prev = curr;
                curr = curr->next;
            }
            last = prev;
        }
        
        last->next = curr;
        
        return root;
}