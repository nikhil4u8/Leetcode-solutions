/*
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
    bool check(TreeNode* root, TreeNode* temp){
        if(!root) return false;
        if(root == temp) return true;
        return check(root->left,temp) || check(root->right,temp);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        bool p_left = check(root->left, p);
        bool q_left = check(root->left, q);

        if(root == p || root == q) return root;
        
        if(p_left && q_left) return lowestCommonAncestor(root->left,p,q);
        //p in right and q in right
        if(!p_left && !q_left) return lowestCommonAncestor(root->right,p,q);
        //p in left and q in right
        //p in right and q in left
        return root;
    }
};