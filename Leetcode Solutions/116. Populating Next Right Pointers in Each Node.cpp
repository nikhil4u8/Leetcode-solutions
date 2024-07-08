/*
Sol :
=> Level order traversal using queue [TIME - O(N) SPACE - O(N)]
    - Use a queue for level order traversal, and link all nodes in a 
    level

=> Level order traversal using parent pointer [TIME - O(N) SPACE - O(1)]
    - Traverse in parent layer meanwhile link their child node, then 
    move parent pointer to child layer, do this until the last layer is 
    reached
*/
class Solution {
public:
//TIME - O(N) SPACE - O(1)
    Node* connect(Node* root) {
        if(!root) return NULL;

        //parent -> first node of the parent level
        //curr -> used to traverse in the parent level
        TreeLinkNode *parent = root, *cur = NULL;

        //checks if this is the last level, in leaf node, parent node won't have children
        while(parent->left) {
            cur = parent;
            //traverse in parent level until it finishes
            while(cur) {
                //linking child of node in parent level
                //linking left to right of a node
                cur->left->next = cur->right;
                //linking right (of one node) to left (of next node)
                if(cur->next) cur->right->next = cur->next->left;
                //moving to next node in parent level
                cur = cur->next;
            }
            //moving parent to next level
            parent = parent->left;
        }
        return root;
    }
};

//USING QUEUE FOR LEVEL ORDER TRAVERSAL 
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            Node* last = NULL;
            while(size--){
                Node* curr = q.front(); q.pop();
                if(last) last->next = curr;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
                last = curr;
            }
            
            last->next = NULL;
        }
        
        return root;
    }
};