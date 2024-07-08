/*
Ques :
    - Can we've empty list?

Sol : 
    - Reverse both the Linked List
    - Traversing reversed LL, and summing up both the nodes in L1 / L2, if one list is already finished then take it's sum as 0
    - Maintaining a prev pointer, to reverse the already reversed LL while traversing it.
    - If both list got exhausted but we still have carry left, then add a new node.

Follow up :
    - Solve it without reversing Input list.
    - Solve it Without reversing list and without using stack

TIME - O(N) SPACE - O(1)
*/
class Solution {
public:
    ListNode* reverse(ListNode* &node){
        if(!node) return NULL;
        ListNode* curr = node,*prev = NULL,*next = curr->next;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* prev = NULL;

        int carry = 0;

        //Run the loop until both list are exhausted and carry == 0
        while(l1 || l2 || carry != 0){
            //Calculating sum of l1 / l2
            int sum = carry;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;

            //finding next carry and current sum
            carry = sum / 10;
            sum %= 10;

            //updating L1 with sum, if L1 is NULL then create new node
            if(l1) l1->val = sum;
            else l1 = new ListNode(sum);
            
            //Moving L2 forward
            if(l2) l2 = l2->next;
            //moving L1 forward while mapping it with prev pointer
            if(l1){
                ListNode* next = l1->next;
                l1->next = prev;
                prev = l1;
                l1 = next;
            }
        }

        return prev;
    }
};

*FOLLOW-UP: 
    1.Could you solve it without reversing the input lists?
        can be done using stack
    2.Without reversing list and without using stack
        can be done using recursion

1.
FOLLOW-UP Solution (USING STACK)
//instead of reversing Linked List, use stack to reverse it.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        ListNode* curr=NULL;
        ListNode* prev=NULL;
        int sum=0,carry=0;
        stack<int>x,y;
        while(a!=NULL)
        {
            x.push(a->val);
            a=a->next;
        }
        while(b!=NULL)
        {
            y.push(b->val);
                b=b->next;
        }
        while(!x.empty() || !y.empty() || carry)
        {   
            sum += carry;
            if(!x.empty())
            {
                sum+=x.top();
                x.pop();
            }
            if(!y.empty())
            {
                sum+=y.top();
                y.pop();
            }

            carry=sum/10;
            sum=sum%10;

            ListNode* temp=new ListNode(sum);

            temp->next=curr;
            curr=temp;            
        }
        return curr;
    }
};

2.
FOLLOW-UP Solution (USING recursion)
Intuition:-
    1.Count total no. of nodes in both linked lists.
    2.If both length are same then we recursively add both list
    3. else append 0's in front of shorter list until len of both list become equal 
    4.Recursively add both the list

class Solution {
public:
    
    int carry = 0;
    void helper(ListNode *l1, ListNode *l2){
        if(!l1 && !l2) return;
        helper(l1->next,l2->next);
        int value = l1->val + l2->val + carry;

        carry = value/10;
        value %= 10;
        
        l1->val = value;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0;
        int n2 = 0;
		
        ListNode* curr = l1;
        while(curr){
            n1++;
            curr=curr->next;
        }
		
        curr = l2;
        while(curr){
            n2++;
            curr=curr->next;
        }
		
        if(n1 == n2) helper(l1,l2);
        else{
            if(n2 > n1){
                swap(l1,l2);
                swap(n1,n2);
            }

            ListNode *curr2 = new ListNode(0);
            ListNode *tempHead = curr2;

            while(n1 > n2+1){
                ListNode *temp = new ListNode(0);
                curr2->next = temp;
                curr2 = temp;
                n1--;
            }

            curr2->next = l2;
            helper(l1,tempHead);
        } 
        
        if(carry){
                ListNode *a = new ListNode(carry);
                a->next = l1;
                return a;
        }

        return l1;
    }
};