/*
Sol : 
=> Convert to inorder : [TIME - O(N) SPACE - O(N)]
    - Simply traverse binary tree in-order to get sorted array.
    - Use this array to create a BST
    - The new root node will be mid element of the array i.e 
    newRoot= Inorder[mid]=2
	- Then recursively add the mid of first half to the left of the tree
    newRoot->left=1
    - And the mid of second half to the right of the tree i.e 
    newRoot->right=3
*/
class Solution {
public:
    vector<TreeNode*> sortedArr;
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraverse(root);
        return sortedArrayToBST(0, sortedArr.size() - 1);
    }
    void inorderTraverse(TreeNode* root) {
        if (root == NULL) return;
        inorderTraverse(root->left);
        sortedArr.push_back(root);
        inorderTraverse(root->right);
    }
    TreeNode* sortedArrayToBST(int start, int end) {
        if (start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = sortedArr[mid];
        root->left = sortedArrayToBST(start, mid - 1);
        root->right = sortedArrayToBST(mid + 1, end);
        return root;
    }
};