class Solution {
public:
    //TIME - O(NlogN) SAPCE - O(N)->recrusive stack
    //TOP-DOWN APPROACH
    int height(TreeNode* root){
        if(!root) return 0;
        return 1 + max(height(root->left),height(root->right)); 
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        if(abs(height(root->left)-height(root->right))<=1 &&
          isBalanced(root->left) && isBalanced(root->right)) return true;
        
        return false;
    }
    
    //TIME - O(N) SPACE - O(N)->recrusive stack
    //BOTTOM-UP SOLUTION
    public boolean isBalanced(TreeNode root) {
        return getHeight(root) != -1;
    }
    
    private int getHeight(TreeNode node) {
        if (node == null) return 0;

        int left = getHeight(node->left);
        int right = getHeight(node->right);

        // left, right subtree is unbalanced or cur tree is unbalanced
        if (left == -1 || right == -1 || abs(left - right) > 1) return -1;

        return max(left, right) + 1;
    }
};