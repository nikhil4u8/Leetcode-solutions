class Solution {
public:
    //TIME - O(N)
    int maxi = 0;
    int calculate(TreeNode* root,bool isleft){
        if(!root) return 0;
        
        int left = calculate(root->left,false);
        int right = calculate(root->right,true);
        
        maxi = max({maxi,1 + left, 1 + right});
        
        if(isleft) return 1 + left;
        return 1 + right;
    }
    int longestZigZag(TreeNode* root) {
        calculate(root,false);
        return maxi-1;
    }
};