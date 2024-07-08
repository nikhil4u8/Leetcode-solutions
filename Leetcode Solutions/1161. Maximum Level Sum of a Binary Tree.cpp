class Solution {
public:
//TIME - O(N) SPACE - O(N)
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN, ans = 0, level = 0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            level++;
            while(size--){
                TreeNode* curr = q.front(); q.pop();
                sum += curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            if(sum > maxSum){
                maxSum = sum;
                ans = level;
            }
        }

        return ans;
    }
};