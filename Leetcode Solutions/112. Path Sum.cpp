class Solution {
public:
    //TIME - O(N) SPACE - O(logN)
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;        
        targetSum -= root->val;
        
        if(!root->left && !root->right) return targetSum==0;

        return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);
    }
};