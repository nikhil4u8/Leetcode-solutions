/*
Ques to ask :
    - Is it a BST or binary tree?
    - Single node?
    - Do we need to do it in-place? or return a deep copy of circular LL?
    - Which pointer to return in end?

Sol :
=> Store nodes in vector then convert to doubly LL : 
-> [TIME - O(N) SPACE - O(N)]
    - Do inorder traversal & store elements in vector then form a DLL using
    them.

BEST APPROACH 
=> Using Inorder Traversal : [TIME - O(N) SPACE - O(N) -> recursive stack]
    - Since it's a BST, so by inorder traversal we can get nodes in sorted 
    order.
    - While doing inorder traversal, we'll maintain a variable to store 
    last node visited, that way we'll keep track of currNode & it's 
    successor, then we can link both as LL.
    - Meanwhile, we'll keep track of head i.e first node in circular LL & 
    tail i.e last node in circular LL & in end link both.

BEST APPROACH - [SAY ONLY WHEN ASKED]
=> Morris Traversal for inorder - [TIME - O(N) SPACE - O(1)]
    - Use Morris traversal to flatten tree into Linked list, the most left 
    will be start of LL.
    - For hasNext() simply see if something is in right or not, and for 
    Next() simply return next element. 
    - In Morris traversal, find highest node in left subtree of root node.
    TreeNode* temp = root->left;
    highest_node_leftSubtree->right = root
    root->left = NULL;
    root = temp;
    
    In end, we make whole tree as a straight inorder traversal linked list. 
*/

class Solution {
public:
//TIME - O(N) SPACE - O(N) -> recursive stack
    Node* last = NULL, *first = NULL;
    void inorder(Node* root){
        if(!root) return;

        inorder(root->left);

        if(last){
            last->right = root;
            root->left = last;
        }else first = root;
        last = root;

        inorder(root->right);
    }
    Node* treeToDoublyList(Node* root){
        if(!root) return NULL;

        inorder(root);
        first->left = last;
        last->right = first;

        return first;
    }
};

//Using Morris Traversal
//TIME - O(n) O(1) O(1) SPACE - O(1)
Node* treeToDoublyList(Node* root){
    if(!root) return NULL;

    TreeNode *tmp, *p = root, *prev = NULL, *tempRoot = NULL;
    while(p) {
        if (p->left == NULL) p = p->right;
        else {  
            tmp = p->left;  
            while (tmp->right != NULL && tmp->right != p) tmp = tmp->right;  
            
            if (tmp->right == NULL) {  
                if(!tempRoot) tempRoot = tmp;
                tmp->right = p;  
                p = p->left;  
            }  
            else {
                tmp->right = NULL;  
                p = p->right;
            }  
        }  
    }
    
    p = tmp;
    while(p){
        p->left = prev;
        prev = p;
        p = p->right;
    }

    return tmp;
}
