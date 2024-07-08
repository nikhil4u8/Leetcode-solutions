class Solution {
public:
//TIME - O(N) SPACE - O(N)
    void printLinkedListInReverse(ImmutableListNode* head) {
        if(head){
            printLinkedListInReverse(head->getNext());
            head->printValue();
        }
    }
};