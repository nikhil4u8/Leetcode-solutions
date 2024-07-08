class Solution {
public:
    //TIME - O(N) SPACE - O(N)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        
        if(!root) return res;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int si = q.size();
            vector<int>v;
            while(si--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                v.push_back(temp->val);
            }
            res.push_back(v);
        }
        
        return res;
    }
};