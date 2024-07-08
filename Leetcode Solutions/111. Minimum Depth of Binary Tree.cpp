class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;

        if(!root->left && !root->right) return 1;
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);

        int mini = INT_MAX;
        if(left != 0) mini = left;
        if(right != 0) mini = min(mini, right);

        return 1 + mini;
    }
};