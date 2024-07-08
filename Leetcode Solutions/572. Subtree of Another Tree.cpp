/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //TIME - (N*M) -> in worst case we need to compare every subtree in original tree with subroot
    bool isSubtree(TreeNode* root, TreeNode* subRoot, bool continuous = false) {
        if(!root && !subRoot) return true;
        
        if((!root && subRoot) || (root && !subRoot)) return false;
        
        bool ans = false;
        
        if(root->val == subRoot->val)
            ans = ans || (
            isSubtree(root->left,subRoot->left, true) && 
            isSubtree(root->right,subRoot->right, true)
        );
        
        if(!continuous)
            ans = ans || (isSubtree(root->left,subRoot, false) || isSubtree(root->right,subRoot,false));
        
        return ans;    
    }
};