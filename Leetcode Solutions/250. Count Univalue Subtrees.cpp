class Solution {
public:
    unordered_map<int, int>mp;
    int maxi = 0;
    bool solve(TreeNode* root){
        if(!root) return true;
        
        bool same_left = solve(root->left);
        bool same_right = solve(root->right);
        bool left = true, right = true;
        
        if(root->left && root->val != root->left->val) left = false;
        if(root->right && root->val != root->right->val) right = false;
        
        if(same_left && same_right && left && right){
            maxi++;
        }
        
        return same_left && same_right && left && right;
    }
    int countUnivalSubtrees(TreeNode* root) {
        solve(root);
        return maxi;
    }
};