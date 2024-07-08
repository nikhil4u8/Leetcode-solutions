/*
Ques to ask :
    - Is the list present in sorted manner?

Sol :
N : total no of nodes
K : lists.size()

=> Brute Force : [TIME - O(NlogN) SPACE - O(N)]
    - Traverse all linked list & store the values in an array, sort this 
    array & create a new sorted linked list having these elements.

=> Merging 2 list at a time using two pointer : [TIME - O(NK) SPACE - O(1)]
    - Start merging 2 Linked list first & merge the resultant linked list 
    with third one, do this until all the linked list are merged

=> Merging K list at same time : [TIME - O(NK) SPACE - O(1)] (IMP to SAY)
    - Instead of merging 2 list at a time, we'll just keep track of last 
    pointer of every linked list & for every iteration to find next 
    element for sorted list, we'll run a for loop to compare all the k 
    nodes (current pointer of every linked list) & get the node with 
    smallest value & increment it's pointer to next & add this node to 
    sorted linked list.

BEST APPROACH
=> Merging using min heap : [TIME - O(NlogK + KlogK) SPACE - O(N)]
-> In every iteration, only 1 element is added so for sorting it PQ takes 
logK time, hence for N iteration time = O(NlogK).
    - Instead of running a for loop to compare all the K pointers of LL,
    we'll just maintain a min heap which will store value of current ptr
    of Linked list & we'll just extract min value & move the pointer of LL
    associated with min val & push the next val of moved ptr & we'll just
    put the min val to ans list

Follow up :
    - Merge K list having duplicate values, but in end array there should
    not be any duplicates.
*/
class Solution {
public:
//BEST APPROACH
//Using min Heap
//TIME - O(NlogK + KlogK) SPACE - O(N)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* head = NULL, *temp = NULL;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>>pq;

        for(int i=0;i<k;i++){
            if(lists[i]) pq.push({lists[i]->val, lists[i]});
        }

        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            ListNode* currPtr = curr.second;
            int minVal = curr.first;

            if(!head){
                head = new ListNode(minVal);
                temp = head;
            }else{
                temp->next = new ListNode(minVal);
                temp = temp->next;
            }

            if(currPtr->next){
                //follow up
                //add when asked to remove duplicate entries
                // while(currPtr->next && currPtr->val == currPtr->next->val) 
                //     currPtr = currPtr->next;

                currPtr = currPtr->next;
                if(currPtr) pq.push({currPtr->val, currPtr});
            }
        }

        return head;
    }
//Approach - 3
//Merging k list by incrementing pointers
//TIME - O(NK) SPACE - O(1)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL, *ans = NULL;

        int k = lists.size();

        while(true){
            int minNum = INT_MAX, idx = -1;
            for(int i=0;i<k;i++){
                if(lists[i]){
                    if(minNum > lists[i]->val){
                        minNum = lists[i]->val;
                        idx = i;
                    }
                }
            }

            if(idx == -1) break;
            lists[idx] = lists[idx]->next;

            if(!head){
                head = new ListNode(minNum);
                ans = head;
            }else{
                ans->next = new ListNode(minNum);
                ans = ans->next;
            }
        }

        return head;
    }
};