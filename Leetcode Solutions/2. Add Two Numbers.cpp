/*
Sol :
    - traversing through both the list, and storing the sum in L1
    - If L1 gets exhausted then add new nodes in that.
    - If L1 / L2 both gets exhausted and carry is left then add new node 
    in that.
*/
class Solution {
public:
//TIME - O(N) SPACE - O(1)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* prev = NULL, *head = l1;

        while(l1 || l2 || carry != 0){
            int sum = carry;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;

            carry = sum / 10;
            sum %= 10;

            if(l1) l1->val = sum;
            else l1 = new ListNode(sum);

            if(l2) l2 = l2->next;
            if(l1){
                if(prev) prev->next = l1;
                prev = l1;
                l1 = l1->next;
            }
        }

        return head;
    }
};

class Solution {
public:
//RECRUSIVE
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        if(!l1 && !l2){
            if(carry != 0) return new ListNode(carry);
            return NULL;
        }

        int sum = 0;
        if(!l1){
            sum = l2->val + carry;
            l2->val = sum%10;
            carry = sum/10;

            l2->next = addTwoNumbers(l1, l2->next, carry);
            return l2;
        }
        if(!l2){
            sum = l1->val + carry;
            l1->val = sum%10;
            carry = sum/10;

            l1->next = addTwoNumbers(l1->next, l2, carry);
            return l1;
        }

        sum = l1->val + l2->val + carry;
        l1->val = sum%10;
        carry = sum/10;

        l1->next = addTwoNumbers(l1->next, l2->next, carry);

        return l1;
    }
};