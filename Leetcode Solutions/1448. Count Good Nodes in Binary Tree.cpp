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
    //TIME - O(N)
    //INORDER TRAVERSAL
    int res = 0;
    void count(TreeNode* root,int maxi){
        if(!root) return;
        
        if(root->val>=maxi) res++;
        
        maxi = max(maxi,root->val);
        
        count(root->left,maxi);
        count(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        count(root,INT_MIN);
        return res;
    }
};