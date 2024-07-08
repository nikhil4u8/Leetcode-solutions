/*
Ques to ask : 
    - Tree Modification allowed? -> If allowed then use Morris traversal
    - If tree modification is allowed then is Tree restoration necessary?

Sol :
=> Inorder Traversal - [TIME - O(N) O(1) O(1) SPACE - O(N)]
    - Just do a inorder traversal, and store all element in an array, and 
    return element from that array. 

BEST APPROACH - IF TREE MODIFICATION NOT ALLOWED  
=> Using Stack - [TIME - O(H) O(1) O(1) SPACE - O(H)]
    - In a stack, keep track of all the left elements, and when calling 
    hasNext() just check if stack has element or not. 
    - In next(), output the first element in stack (left most element of 
    the unvisited tree => smallest one) and pop it and push all left child
    of it's unvisited right child (and all left node under that).

BEST APPROACH - IF TREE MODIFICATION ALLOWED  
=> Morris Traversal - [TIME - O(N) O(1) O(1) SPACE - O(1)]
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
//Using Array
class BSTIterator {
public:
//Approach 1 : Inorder Traversal
//TIME - O(N) O(1) O(1)
//Space - O(N)
    vector<int>v;
    TreeNode* head;
    int count = 0;
    void inorder(TreeNode* root){
        if(!root) return;
        
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        head = root;
        inorder(root);
        count = 0;
    }
    int next() {
        return v[count++];
    }
    bool hasNext() {
        return count<v.size();   
    }
};
//BEST APPROACH : If tree modification not allowed.
//Using Stack
//TIME - O(H) O(1) O(1)
//SPACE - O(H)
class BSTIterator {
public:
    stack<TreeNode*> s;
    
    BSTIterator(TreeNode* root) {
        left(root);
    }
    int next() {
        TreeNode* toper=s.top();
        s.pop();
        if(toper->right) left(toper->right);
        return toper->val;
    }
    bool hasNext() {
        return s.size()>0;
    }
    void left(TreeNode* root){
        if(root==NULL) return ;
        s.push(root);
        left(root->left);
    }

//Using Morris Traversal
//TIME - O(n) O(1) O(1) SPACE - O(1)
class BSTIterator {
public:
    TreeNode *p;
    BSTIterator(TreeNode *root) {
        p = root;
    }
    bool hasNext() {
        return p != NULL;
    }
    int next() {
        TreeNode *tmp;
        int ret;
        while(p) {
            if (p->left == NULL) {  
                ret = p->val;
                p = p->right;
                break;
            }  
            else {  
                tmp = p->left;  
                while (tmp->right != NULL && tmp->right != p)  
                    tmp = tmp->right;  
                if (tmp->right == NULL) {  
                    tmp->right = p;  
                    p = p->left;  
                }  
                else {
                    ret = p->val;
                    tmp->right = NULL;  
                    p = p->right;
                    break;
                }  
            }  
        }
        
        return ret;
    }
};