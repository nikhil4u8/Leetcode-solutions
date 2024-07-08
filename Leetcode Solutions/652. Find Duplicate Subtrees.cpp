class Solution {
public:
    //TIME - O(N) SPACE - O(N)
    vector<TreeNode*>v;
    unordered_map<string,pair<int,bool>>mp;
    string solve(TreeNode* root){
        if(!root) return "$";
        
        string str = to_string(root->val) + ',' + solve(root->left) + ',' + solve(root->right);
        
        mp[str].first++;
        if(mp[str].first>1 && !mp[str].second){
            v.push_back(root);
            mp[str].second = true;
        }
        
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return v;
    }
};