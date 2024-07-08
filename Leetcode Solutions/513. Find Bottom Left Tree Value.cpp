class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            while(size--){
                if(!flag) ans = q.front()->val;
                auto t = q.front();
                q.pop();
                
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                flag = true;
            }
        }
        
        return ans;
    }
};