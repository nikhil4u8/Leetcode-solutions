class Solution {
public:
    //TIME - O(N^2)  SPACE - O(N)->height of tree could be N in worst case
    //For every node check if it form a BST or not, if it does then 
    //maxi=max(maxi,count_node_in_curr_BST)
    int maxi = 0;
    bool isvalid(TreeNode* root,int mini,int maxi,int &count_node){
        if(!root) return true;
        
        count_node++;
        if(mini==INT_MIN && root->val==INT_MIN){
            if(root->left) return false;
            return isvalid(root->right,mini+1,maxi,count_node);
        } 
        if(maxi==INT_MAX && root->val==INT_MAX){
            if(root->right) return false;
            return isvalid(root->left,mini,maxi-1,count_node);
        }
           
        if(root->val>=mini && root->val<=maxi) return isvalid(root->left,mini,root->val-1,count_node) &&
                                                   isvalid(root->right,root->val+1,maxi,count_node);
           
        return false;
    }
    void largest_BST(TreeNode* root){
        if(!root) return;
        
        int count_node = 0;
        bool check = isvalid(root,INT_MIN,INT_MAX,count_node);
        if(check){
            maxi = max(maxi,count_node);
            return;
        }
        
        largest_BST(root->left);
        largest_BST(root->right);
    }
    int largestBSTSubtree(TreeNode* root) {
        largest_BST(root);
        return maxi;
    }
    //TIME - O(N) SPACE - O(N)
    //Calculating total_nodes by one traversal only
    bool isBST(TreeNode* root, int& res, int& mini, int& maxi) {
        if(!root) return true;
        
        int left_size=0, right_size=0;
        int left_mini, left_maxi, right_mini, right_maxi;
        
        bool leftBST = isBST(root->left, left_size, left_mini, left_maxi);
        bool rightBST = isBST(root->right, right_size, right_mini, right_maxi);

        if (leftBST && rightBST) {
            if ((!root->left || root->val >= left_maxi) && (!root->right || root->val<=right_mini) ) {
                /* The tree rooted at this node is a binary search tree */
                res = left_size+right_size+1;
                
                mini = root->left ? left_mini : root->val;
                maxi = root->right ? right_maxi : root->val;
                return true;
            }
        }
        // The tree rooted at this node is not a binary search tree, so take the maximum size of the 
        //BST in the left or right subtrees 
        res = max(left_size, right_size);
        return false;
    }
    int largestBSTSubtree(TreeNode* root) {
        
        int res = 0;
        int mini, maxi;
        bool b = isBST(root, res, mini, maxi);

        return res;
    }
};