class Solution {
public:
    int ans = 1;
    int LCS(TreeNode* root, int diff){
        if(!root) return 0;
        
        if(!root->left && !root->right) return 1;
        
        int left_inc = 0, left_dec = 0, right_inc = 0, right_dec = 0;
        
        if(root->left){
            int _diff = root->val - root->left->val;
            
            if(_diff == 1) left_inc = LCS(root->left, 1);
            else if(_diff == -1) left_dec = LCS(root->left, -1);
            else LCS(root->left, 1);
        }
        if(root->right){
            int _diff = root->val - root->right->val;
            
            if(_diff == 1) right_inc = LCS(root->right, 1);
            else if(_diff == -1) right_dec = LCS(root->right, -1);
            else LCS(root->right, 1);
        }
        
        if(root->left && root->right){
            int diff1 = root->val - root->left->val;
            int diff2 = root->val - root->right->val;
            
            if(diff1 == 1 && diff2 == -1) 
                ans = max(ans, 1 + left_inc + right_dec);
            else if(diff1 == -1 && diff2 == 1) 
                ans = max(ans, 1 + left_dec + right_inc);
        }
        
        int temp_ans = 1;
        
        if(root->left){
            int diff1 = root->val - root->left->val;
            
            if(diff1 == 1){
                if(diff1 == diff) 
                    temp_ans = max(temp_ans, 1 + left_inc);
                ans = max(ans, 1 + left_inc);
            }else if(diff1 == -1){
                if(diff1 == diff) 
                    temp_ans = max(temp_ans, 1 + left_dec);
                ans = max(ans, 1 + left_dec);
            }
        }
        if(root->right){
            int diff2 = root->val - root->right->val;
            
            if(diff2 == 1){
                if(diff2 == diff) 
                    temp_ans = max(temp_ans, 1 + right_inc);
                ans = max(ans, 1 + right_inc);
            }else if(diff2 == -1){
                if(diff2 == diff) 
                    temp_ans = max(temp_ans, 1 + right_dec);
                ans = max(ans, 1 + right_dec);
            }
        }
        
        return temp_ans;
    }
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        LCS(root, -1);
        
        return ans;
    }
};