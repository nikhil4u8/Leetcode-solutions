class Solution {
public:
    //TIME - O(N) SPACE - O(1)
    int maxi = INT_MIN;
    int maxi_path_sum(TreeNode* root){
        if(!root) return 0;
        
        int left = max(maxi_path_sum(root->left),0);
        int right = max(maxi_path_sum(root->right),0);
        
        maxi = max(maxi,root->val+left+right);

        return root->val + max({left,right});
    }
    int maxPathSum(TreeNode* root) {
        maxi_path_sum(root);
        return maxi;
    }
};