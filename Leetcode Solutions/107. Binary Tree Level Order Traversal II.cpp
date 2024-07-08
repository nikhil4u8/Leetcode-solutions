class Solution {
public:
    //TIME - O(N) SPACE - O(N)
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            vector<int>v;
            int si = q.size();
            while(si--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                v.push_back(temp->val);
            }
            res.push_back(v);
        }
        
        reverse(res.begin(),res.end());
        return res; 
    }
};