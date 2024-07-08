/*
Ques to ask:
    - Is the list sorted in increasing / decreasing order?
    - What if we've multiple places to insert val?
    - What if list is initially empty?

Sol :
=> Linear traversal : [TIME - O(N) SPACE - O(1)]
    - Since LL is sorted in ascending order, so we'll traverse from head 
    node, maintaing curr & prev pointer.
    - Traverse LL and check for these cases when insert will happen:
        1. prev <= insertVal <= next
        2. insertVal < min (insert at the tail)
        3. insertVal > max (insert at the tail)
    
Edge case :
    - 3->3->3 insert 0
    - 3->5->7 insert 0 / 9
    - 3->5->7 insert 6
*/
class Solution {
public:
//TIME - O(N) SPACE - O(1)
    Node* insert(Node* head, int insertVal) {
        Node* tempNode = new Node(insertVal);
        tempNode->next = tempNode;

        if(!head) return tempNode;

        Node *prev = head, *next = head->next;
        bool isInserted = false;

        do{
            // insert when: [LL is sorting in non decreasing order]
            // 1. prev <= insertVal <= next
            // 2. insertVal < min (insert at the tail)
            // 3. insertVal > max (insert at the tail)
            if ((prev->val <= insertVal && insertVal <= next->val) ||
                (prev->val > next->val && 
                    (insertVal < next->val || insertVal > prev->val))) {
                prev->next = tempNode;
                tempNode->next = next;
                isInserted = true;
                break;
            }

            prev = prev->next;
            next = next->next;
        }while(prev != head);

        if (!isInserted) {
            // The only reason why `value` was not inserted is that
            // all values in the list are the same and are not equal to `value`.
            // So, we could insert `value` anywhere.
            prev->next = tempNode;
            tempNode->next = next;
        }

        return head;
    }
};