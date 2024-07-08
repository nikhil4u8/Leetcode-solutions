class Solution {
public:
    //TIME - O(N) SPACE - O(N)->queue
    //LEVEL ORDER TRAVERSAL
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int si = q.size();
            while(si--){
                Node* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
                if(si == 0) temp->next = NULL;
                else temp->next = q.front();
            }
        }
        
        return root;
    }
    //TIME - O(N) SPACE - O(1)
    Node* connect(Node* root) {
        if(!root) return NULL;
        root->next = NULL;
        
        Node* curr = root,*start=root;
        
        while(curr->left && curr->right){
            curr->left->next = curr->right;
            if(curr->next){
                curr->right->next = curr->next->left;
                curr = curr->next;
            }else{
                curr->right->next = NULL;
                curr = start->left;
                start = curr;
            }
        }
        return root;
    }
    
};