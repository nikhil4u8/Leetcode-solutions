class Solution {
public:
    //RECRUSIVE APPROACH
    //TIME - O(N) SPACE - O(logN) -> for recrusive stack
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if((!p && q) || (p && !q)) return false;
        
        return p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    //ITERATIVE
    //TIME - O(N) SPACE - O(logN)
    public boolean isSameTree(TreeNode p, TreeNode q) {
        Queue<TreeNode> queue = new LinkedList<>();
        if (p == null && q == null)
            return true;
        else if (p == null || q == null)
            return false;
        if (p != null && q != null) {
            queue.offer(p);
            queue.offer(q);
        }
        while (!queue.isEmpty()) {
            TreeNode first = queue.poll();
            TreeNode second = queue.poll();
            if (first == null && second == null)
                continue;
            if (first == null || second == null)
                return false;
            if (first.val != second.val)
                return false;
            queue.offer(first.left);
            queue.offer(second.left);
            queue.offer(first.right);
            queue.offer(second.right);
        }
        return true;
    }
};