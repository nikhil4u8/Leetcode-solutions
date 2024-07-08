class Solution {
public:
    //TIME - O(N) SPACE - O(N)
    vector<TreeNode*>order;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        order.push_back(root);
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL,*second = NULL;
        inorder(root);
        
        for(int i=1;i<order.size();i++){
            if(order[i]->val<order[i-1]->val){
               if(!first) first = order[i-1];
               second = order[i];
            }
        }
        
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    //TIME - O(N) SPACE - O(N)->recursive stack
  TreeNode *x=NULL,*y=NULL,*pred = NULL;
  void findTwoSwapped(TreeNode* root) {
    if (!root) return;
    
    findTwoSwapped(root->left);
    if(pred && root->val<pred->val) {
      y = root;
      if(!x) x = pred;
      else return;
    }
    pred = root;
    findTwoSwapped(root->right);
  }
  void recoverTree(TreeNode* root) {
    findTwoSwapped(root);
    swap(x->val,y->val);
  }
};