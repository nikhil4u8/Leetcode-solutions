/*
Ques to ask :
    - Does tree have equal values?

Sol :
    - We'll do a simple tree traversal and keeping track of min / max 
    value which is applicable for every node
*/
//TIME - O(N) SPACE - O(N) -> recursive stack
class Solution {
public:
    bool isValidBST(TreeNode* root, int max_val = INT_MAX, int min_val = INT_MIN) {
        if(!root) return true;

        if(max_val == INT_MAX && root->val == max_val)
            return isValidBST(root->left, root->val-1, min_val) && 
                   root->right == NULL;
        
        if(min_val == INT_MIN && root->val == min_val)
            return isValidBST(root->right, max_val, root->val+1) &&
                   root->left == NULL;

        //doing -1 / +1 is imp, becoz when root->val == INT_MAX, and 
        //you'll pass max_val is INT_MAX only, without decrementing it, 
        //then the root child can also have value to be INT_MAX
        return root->val >= min_val && root->val <= max_val && 
               isValidBST(root->left, root->val-1, min_val) && 
               isValidBST(root->right, max_val, root->val+1);
    }
};