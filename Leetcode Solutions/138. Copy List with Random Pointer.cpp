//Edge case :- When there is a loop.
class Solution {
public:
    //O(N) time and O(N) space -> space accured by map
//USING MAP
    //Just store the orignal nodes as key in a map with copy nodes as values
    //then assign the corresponding next and radom pointers EASILY
 Node* copyRandomList(Node* head) {
        
        unordered_map<Node*,Node*> mp;
        Node* orig = head;
        Node* copy=NULL;
        
        while(orig)
        {
            copy = new Node(orig->val);
            mp[orig]=copy;
            orig=orig->next;
        }
        orig=head;
        while(orig)
        {
            copy = mp[orig];
            copy->next=mp[orig->next];
            copy->random=mp[orig->random];
            orig=orig->next;
        }
        return mp[head];
    }
    //Adding new node next to original node
    //mapping to random node
    //seperating two list
    //TIME - O(N)  SPACE - O(1)
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        Node* curr = head;
        //adding a new node next to each node
        while(curr){
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            
            curr = temp->next;
        }
        
        curr = head;
        //mapping random pointer of added new nodes
        while(curr){
            if(curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        
        curr = head;
        Node* root = curr->next;
        //removing added new node list from old node and returning it
        while(curr){
           if(curr->next->next){
               Node* t = curr->next;
               curr->next = curr->next->next;
               t->next = t->next->next;
           }else{
               curr->next->next = NULL;
               curr->next = NULL;
           }
            curr = curr->next;
        }
        
        return root;
    }
};