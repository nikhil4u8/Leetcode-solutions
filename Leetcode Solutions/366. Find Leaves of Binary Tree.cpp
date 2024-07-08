class Solution {
public:
    unordered_map<TreeNode*, int>mp;
    int maxi = 0;
    
    int node_number(TreeNode* root){
        if(!root) return 0;
        
        int left = node_number(root->left);
        int right = node_number(root->right);
        
        int res = max(left,right);
        mp[root] = res;
        
        maxi = max(maxi, res+1);
        
        return res + 1;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        node_number(root);
        
        vector<vector<int>>ans(maxi,vector<int>());
        
        for(auto it : mp){
            ans[it.second].push_back(it.first->val);
        }
        
        return ans;
    }
};