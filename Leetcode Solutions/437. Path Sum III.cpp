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
    int res = 0;
    void solve(TreeNode* root,int targetSum,unordered_map<int,int>mp,int sum){
        if(!root) return;
        
        sum += root->val;

        res += mp[sum-targetSum];
        mp[sum]++;
        
        solve(root->left,targetSum,mp,sum);
        solve(root->right,targetSum,mp,sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int,int>mp;
        mp[0]++;
        solve(root,targetSum,mp,0);
        return res;
    }
    //TIME - O(N2) SPACE - O(N)->recursive
    int sumUp(TreeNode* root, int pre, int& sum){
        if(!root) return 0;
        int current = pre + root->val;
        return (current == sum) + 
               sumUp(root->left, current, sum) + 
               sumUp(root->right, current, sum);
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};