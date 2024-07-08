class Solution {
public:
    //TIME - O(N) SPACE - O(N)->recrusive stack
    void greater_BST(TreeNode* root,int &sum){
        if(!root) return;
        
        greater_BST(root->right,sum);
        sum += root->val;
        root->val = sum;
        greater_BST(root->left,sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        greater_BST(root,sum);
        
        return root;
    }
    
    //TIME - O(N) SPACE - O(1)
    //MORRIS TRAVERSAL
    private TreeNode getSuccessor(TreeNode node) {
        TreeNode succ = node.right;
        while (succ.left != null && succ.left != node) {
            succ = succ.left;
        }
        return succ;
    }

    public TreeNode convertBST(TreeNode root) {
        int sum = 0;
        TreeNode node = root;

        while (node) {
            
            //If there is no right subtree, then we can visit this node and continue traversing left. 
            if (node.right == null) {
                sum += node.val;
                node.val = sum;
                node = node.left;
            }
            // If there is a right subtree, then there is at least one node that has a greater value 
            // than the current one. therefore, we must traverse that subtree first.
            else {
                TreeNode succ = getSuccessor(node); 
                //If the left subtree is null, then we have never been here before.
                if (succ.left == null) {
                    succ.left = node;
                    node = node.right;
                }
                /* 
                 * If there is a left subtree, it is a link that we created on a
                 * previous pass, so we should unlink it and visit this node.
                 */
                else {
                    succ.left = null;
                    sum += node.val;
                    node.val = sum;
                    node = node.left;
                }
            }
        }
        
        return root;
    }
};