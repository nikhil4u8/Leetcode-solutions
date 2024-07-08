class Solution {
public:
    //TIME - O(N)
    TreeNode* succ = NULL,*pre = NULL;
    void inorder(TreeNode* root,TreeNode* p){
        if(!root) return;
        
        inorder(root->left,p);
        if(pre && pre == p) succ = root;
        pre = root;
        inorder(root->right,p);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        inorder(root,p);
        
        return succ;
    }
    //time - O(logN) 
    //ITERATIVE
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* succ = NULL;
        while(root){
            if(p->val >= root->val) root = root->right;
            else{
                succ = root;
                root = root->left;
            }
        }
        
        return root;
    }
};

**FOLLOW-UP
    1.If tree is not BST
    2.Predecessor instead of successor
1. Use proper recursive/iterative inorder traversal
2.
TreeNode* predecessor(TreeNode* root, TreeNode* p) {
  if(!root) return NULL;

  if (root->val >= p->val) return predecessor(root->left, p);
  else TreeNode* right = predecessor(root->right, p);
    
  return right ? right : root;
}