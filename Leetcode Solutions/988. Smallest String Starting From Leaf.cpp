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
    //TIME - O(N) SPACE - O(N)->recruisve stack
    int mini = INT_MAX;
    string res = "";
    void solve(TreeNode* root,string str){
        if(!root) return;
        
        if(!root->left && !root->right){
            str += 'a'+root->val;
            reverse(str.begin(),str.end());
            
            if(res=="") res = str;
            else res = min(res,str);
            
            return;
        }
        
        str += 'a'+root->val;
        solve(root->left,str);
        solve(root->right,str);
    }
    string smallestFromLeaf(TreeNode* root) {
        solve(root,"");
        return res;
    }
};