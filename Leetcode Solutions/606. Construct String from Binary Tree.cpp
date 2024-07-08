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
    //TIEM - O(N) SPACE - O(N)
    string tree2str(TreeNode* root) {
        if(!root) return "";

        string path = to_string(root->val);
        
        if(!root->left && !root->right) return path;

        path += '(' + tree2str(root->left) + ')';
        if(root->right) path += '(' + tree2str(root->right) + ')';

        return path;
    }
};