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
    vector<int>leaf(TreeNode* root){
        if(!root) return {};
        
        if(!root->left && !root->right) return {root->val};
        
        vector<int>ans = leaf(root->left);
        vector<int>temp = leaf(root->right);
        
        ans.insert(ans.end(), temp.begin(), temp.end());
        
        return ans;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        
        vector<int>leaf1 = leaf(root1);
        vector<int>leaf2 = leaf(root2);
        
        if(leaf1.size() != leaf2.size()) return false;
        
        for(int i=0;i<leaf1.size();i++){
            if(leaf1[i] != leaf2[i]) return false;
        }
        return true;
    }
};