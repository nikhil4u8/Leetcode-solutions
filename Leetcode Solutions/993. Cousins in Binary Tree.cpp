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
    //TIME - O(N) SPACE - O(N)
    pair<int,int> solve(TreeNode* root,int val,int par){
        if(!root) return {-1,-1};
        
        if(root->val == val) return {1,par};
        
        auto left = solve(root->left,val,root->val);
        auto right = solve(root->right,val,root->val);
        
        if(left.first!=-1 && right.first==-1) return {left.first+1,left.second};
        if(left.first==-1 && right.first!=-1) return {right.first+1,right.second};
        
        return {-1,-1};
    }
    bool isCousins(TreeNode* root, int x, int y) {
        
        auto t1 = solve(root,x,-1);
        auto t2 = solve(root,y,-1);
        
        return t1.first == t2.first && t1.second!=t2.second && t1.first!=-1;
    }
};