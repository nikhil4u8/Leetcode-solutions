class Solution {
public:
    //Recursive Traversal with valid Range
    //TIME - O(N) SPACE - O(N) recursive stack
    bool isvalid(TreeNode* root,int mini,int maxi){
        if(!root) return true;
        
        if(mini==INT_MIN && root->val==INT_MIN){
            if(root->left) return false;
            return isvalid(root->right,mini+1,maxi);
        } 
        if(maxi==INT_MAX && root->val==INT_MAX){
            if(root->right) return false;
            return isvalid(root->left,mini,maxi-1);
        }
           
        if(root->val>=mini && root->val<=maxi) return isvalid(root->left,mini,root->val-1) &&
                                                   isvalid(root->right,root->val+1,maxi);
           
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return isvalid(root,INT_MIN,INT_MAX);
    }
    //Recursive Inorder Traversal
    bool inorder(TreeNode* root) {
        if (!root)  return true;
        
        if (!inorder(root->left))  return false;
        if (prev != nullptr && root->val <= prev->val)  return false;
        prev = root;

        return inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
    //Iterative Inorder traversal
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*>sta;
        TreeNode* prev = NULL;

        while (!stk.empty() || root) {
            while (root){
                sta.push(root);
                root = root->left;
            }
            root = sta.top();
            stk.pop();

            if(prev && root->val <= prev->val) return false;
            
            prev = root;
            root = root->right;
        }
        return true;
    }
};

 //Iterative traversal with Range
class Solution {
private:
    stack<TreeNode*> stk, lower_limits, upper_limits;

public:
    void update(TreeNode* root, TreeNode* low, TreeNode* high) {
        stk.push(root);
        lower_limits.push(low);
        upper_limits.push(high);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* low = NULL;
        TreeNode* high = NULL;
        update(root, low, high);

        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            low = lower_limits.top();
            lower_limits.pop();
            high = upper_limits.top();
            upper_limits.pop();

            if (!root) continue;

            TreeNode* val_node = root;
            if(low && val_node->val <= low->val)  return false;
            
            if(high && val_node->val >= high->val)  return false;
            
            update(root->right, val_node, high);
            update(root->left, low, val_node);
        }
        return true;
    }
};
