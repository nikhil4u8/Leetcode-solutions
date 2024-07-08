class Solution {
public:
    
    //TIME - O(N) SPACE - O(LOGN)
    //RECURSIVE
    bool sym(TreeNode* p,TreeNode* q){
        if(!p && !q) return true;
        if((!p && q) || (p && !q)) return false;
        
        return p->val == q->val && sym(p->left,q->right) && sym(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return sym(root,root);
    }
    
    
    //ITERATIVE
    bool isSymmteric(TreeNode* root){
         if (root == null) {
      return true;
    }

    Queue<TreeNode> q = new LinkedList<>();
    q.add(root.left);
    q.add(root.right);
    
    while (!q.isEmpty()) {
      TreeNode t1 = q.poll();
      TreeNode t2 = q.poll();

      if (t1 == null && t2 == null)  continue;
      if (t1 == null || t2 == null)  return false;
      if (t1.val != t2.val)  return false;
    
      q.add(t1.left);
      q.add(t2.right);
      q.add(t1.right);
      q.add(t2.left);
    }
    return true;
    }
};