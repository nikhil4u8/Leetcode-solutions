/*
Sol :
    - Will do a level order traversal, and as we travel in a level, 
    then we can connect adjacent nodes to each other with next pointer
*/
class Solution {
public:
    //TIME - O(N)  SPACE - O(N)
    Node* connect(Node* root) {
        if(!root) return NULL;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            //keeps track of the prev node in a level which needs to be connected to the curr node
            Node* prev = NULL;
            //traversing level
            while(size--){
                Node* temp = q.front();
                q.pop();
                
                if(prev) prev->next = temp;
                
                prev = temp;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            prev->next = NULL;
        }
        
        return root;
    }

};


**FOLLOW-UP
    1. using constant space
    2. using recursion

//Follow up
1.
//Using the already connected parent level, we'll traverse into it 
//and connect the child level with each other
    //constant space
    //TIME - O(N) SPACE - O(1)
    Node* connect(Node* root) {
        if(!root) return NULL;
        
        Node* curr = root,*next_start=NULL;
        root->next = NULL;
    
        while(curr){
            Node *last=NULL,*head=curr;
                
            while(head){
                if(head->left){
                    if(!last) next_start = head->left;
                    if(last) last->next = head->left;
                    last = head->left;
                }
                if(head->right){
                    if(!last) next_start = head->right;
                    if(last) last->next = head->right;
                    last = head->right;
                }
                head = head->next;
            }
            
            curr = next_start;
            next_start = NULL;
        }
        
        return root;
    }

2.
    //Recursive
    //TIME - O(N) SPACE - O(N)->recursive stack
    Node* connect(Node* root) {
        if(!root) return NULL;
      
        Node* next = NULL;
        Node* rootNext = root->next;
        
        while(rootNext && !next) {
            next = rootNext->left ? rootNext->left : rootNext->right;
            rootNext = rootNext->next;
        }
      
        if(root->right) root->right->next = next;
        if(root->left) root->left->next = !root->right ? next : root->right;
      
      
        connect(root->right);
        connect(root->left);
        
        return root;
    }