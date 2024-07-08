class Solution {
public:
    //time - o(n) space - o(n)
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int>sta;
        int n=0;
        ListNode* curr = head,*prev=NULL,*next=NULL;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            n++;
        }
        
        vector<int>ans(n,0);
        int i=0;
        while(prev){
            while(!sta.empty() && prev->val>=sta.top()) sta.pop();
            
            if(sta.empty()) ans[n-i-1] = 0;
            else ans[n-i-1] = sta.top();
            
            sta.push(prev->val);
            prev = prev->next;
            i++;
        }
        
        return ans;
    }
};