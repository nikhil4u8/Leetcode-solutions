class Solution {
public:
    //TIME - O(2*N) ->since every node is visited twice
    //ITERATIVE
    Node* flatten(Node* head){
        Node* curr = head;
        while(curr){
            if(curr->child){
                Node* temp = curr->next;
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
                Node* t = curr->next;
                
                while(t->next) t=t->next;
                
                t->next = temp;
                if(temp) temp->prev = t;
            }
            curr = curr->next;
        }
        return head;
    }
    //TIME - O(N)
    //RECURSIVE
    Node* flatten(Node* head) {
        if(!head) return NULL;

        Node* curr = head, *prev = NULL, *next = head;

        while(curr && !curr->child) curr = curr->next;
        if(!curr) return head;

        next = curr->next;
        Node* child = flatten(curr->child);
        curr->child = NULL;
        curr->next = child;
        child->prev = curr;

        while(curr && curr->next) curr = curr->next;
        
        if(next == NULL) return head;
        next->prev = curr;
        curr->next = flatten(next);

        return head;
    }
    //TIME - O(N)
    //RECRUSIVE + ITERATIVE
    Node* flatten(Node* head) {
        Node* curr = head;
        
        while(curr){
            if(curr->child){
                Node* temp = flatten(curr->child);
                Node* t = curr->next;
                curr->next = temp;
                temp->prev = curr;
                curr->child = NULL;
                
                while(temp->next) temp = temp->next;
                
                temp->next = t;
                if(t) t->prev = temp; 
            }
            curr = curr->next;
        }

        return head;
    }
};