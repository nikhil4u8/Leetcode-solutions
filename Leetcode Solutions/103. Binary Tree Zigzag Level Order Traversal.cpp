class Solution {
public:
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        
        if(!root) return res;
        
        bool flag = true;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int si = q.size();
            vector<int>v(si,0);
            int i=0;
            while(i<si){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
                if(!flag) v[si-i-1] = temp->val;
                else v[i] = temp->val;
                
                i++;
            }
            res.push_back(v);
            flag = !flag;
        }
        
        return res;
    }
};