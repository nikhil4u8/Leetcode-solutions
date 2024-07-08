class Solution {
public:
    int res = -1;
    void inorder(TreeNode* root,int &k){
        if(!root) return;
        
        inorder(root->left,k);
        k--;
        if(k==0) res = root->val;
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return res;
    }
};

**FOLLOW-UP
    1. If the BST is modified often (i.e., we can do insert and delete operations) and you need to 
    find the kth smallest frequently, how would you optimize?

For fast queries with frequent insert/delete, maintain a pointer to the kth node of the BST by 
in-order traversal. For each insert, if the node will be inserted before the kth node by in-order 
traversal, move pointer to the previous node. For each delete, if the node to be deleted is before 
the kth node then move pointer to the next node. This will require the BST to be modified to contain 
parent pointers, since you need a way to backtrack the in-order traversal. Run-time would be O(1) for 
look-up and O(1) for updating.