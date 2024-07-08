class Solution {
public:
    vector<TreeNode*>ans;
    TreeNode* solve(TreeNode* root, unordered_set<int>st){
        if(!root) return NULL;
        
        if(st.find(root->val) != st.end()){
            TreeNode* left = solve(root->left, st);
            TreeNode* right = solve(root->right, st);
            
            if(left) ans.push_back(left);
            if(right) ans.push_back(right);
            
            return NULL;
        }
        
        root->left = solve(root->left, st);
        root->right = solve(root->right, st);
        
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>st(to_delete.begin(), to_delete.end());
        root = solve(root, st);
        if(root) ans.push_back(root);
        
        return ans;
    }
};