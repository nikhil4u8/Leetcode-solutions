//
class Solution {
public:
    vector<int>res;
    int max_count = 0, prev_val = INT_MIN, curr_count = 0;
    void inorder(TreeNode* root){
        if(!root) return;
        
        inorder(root->left);
        
        if(prev_val == root->val) curr_count++;
        else curr_count = 1;
        
        if(curr_count > max_count){
            res.resize(0);
            res.push_back(root->val);
            max_count = curr_count;
        }else if(curr_count == max_count)
            res.push_back(root->val);
        
        prev_val = root->val;
        
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        
        return res;
    }
};