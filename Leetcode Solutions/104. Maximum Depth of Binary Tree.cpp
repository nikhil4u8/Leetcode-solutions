class Solution {
public:
    //TIME - O(N) SPACE - O(logN)
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};