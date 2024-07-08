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
    int widthOfBinaryTree(TreeNode* root) {
       if(!root) return 0;
        
        queue<pair<TreeNode*,unsigned long long int>>q;
        q.push({root,0});
        unsigned long long int width = 0;
        
        while(!q.empty()){
            int si = q.size();
            unsigned long long int l=q.front().second,r=0;
            
            while(si--){
                auto temp = q.front();
                q.pop();
                r = temp.second;
                if(temp.first->left) q.push({temp.first->left,2*temp.second+1});
                if(temp.first->right) q.push({temp.first->right,2*temp.second+2});
            }
            
            width = max(width,r-l+1);
        }
        
        return width;
    }
};