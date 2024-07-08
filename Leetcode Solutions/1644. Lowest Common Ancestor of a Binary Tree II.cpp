/*
Desc : Find LCA if p or q doesn't exist in a tree?

Ques to ask :
    - If p/q both are NULL?

Sol :
=> Inorder Traversal & storing path in vector - [TIME - O(N) SPACE - O(H)]
    - Store path from Root node to P / Q node in a vector using inorder 
    traversal.
    - Compare both vector & return the last common node found in both 
    vector

BEST APPROACH
=> Finding node in subtree - [TIME - O(2*N) SPACE - O(N) -> stack size]
    - Firstly, we'll check if p or q are present in tree or not.
    - Instead of storing path in vector, we can simply check if both the 
    P / Q nodes are found in different / same subtree of root node.
    - If found in different subtree or root is P/Q node, then return root.
    - If found in same subtree then reduce search space to that subtree only, 
    and repeat step 2.

Follow ups:
    - How to solve when a parent pointer is given?
        -> Ref : 1650. Lowest Common Ancestor of a Binary Tree III
    - Find LCA of multiple nodes
    - Find path between p / q
    - What if tree doesn't contain p / q ? 
        -> before recursion check if P/Q are present, if not present then 
        return Null, otherwise recrusion
        -> 1644. Lowest Common Ancestor of a Binary Tree II
    - What will happen if we want to find LCA for q queries?
        -> store the parent of every node in the tree and then find the 
        LCA in O(H) time, didn’t have the time to code it. 

Similar ques : 
    - Ref 236. Lowest Common Ancestor of a Binary Tree
    - Ref 1123. Lowest Common Ancestor of Deepest Leaves
    - Ref 1650. Lowest Common Ancestor of a Binary Tree III
    - Ref 235. Lowest Common Ancestor of a Binary Search Tree
    - Ref 1644. Lowest Common Ancestor of a Binary Tree II
*/
class Solution {
public:
//TIME - O(N) SPACE - O(N) -> recursive stack
    bool dfs(TreeNode* root, TreeNode* target) {
        if(!root) return false;
        if (root == target) return true;
        return dfs(root->left, target) || dfs(root->right, target);
    }
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if (root == p || root == q) return root;

        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);
        
        if (left && right) return root;
        else if (left) return left;
        return right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //check if p/q exist
        if(!(dfs(root, p) && dfs(root, q))) return NULL;

        //if exist find their LCA
        TreeNode* ans = LCA(root, p, q);
        return ans;
    }
};