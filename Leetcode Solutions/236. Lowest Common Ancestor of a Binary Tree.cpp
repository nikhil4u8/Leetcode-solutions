/*
Desc : No parent link given to each node.

Ques to ask :
    - If p/q doesn't exist?
    - If both are NULL?
    - Can a node be descendant of itself i.e p = q?

Sol :
=> Inorder Traversal & storing path in vector - [TIME - O(N) SPACE - O(H)]
    - Store path from Root node to P / Q node in a vector using inorder 
    traversal.
    - Compare both vector & return the last common node found in both 
    vector

BEST APPROACH
=> Finding node in subtree - [TIME - O(2*N) SPACE - O(N) -> stack size]
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
//BEST SOLUTION
//TIME - O(N) SPACE - O(N)
//TIME - O(N + N/2 + N/4 + N/8.....) = O(2*N)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        // FIRST CONDITION
        if(root->val == p->val || root->val == q->val) return root;       

        // traverse on the left part of the tree
        TreeNode* lca1 = lowestCommonAncestor(root->left, p, q);          
        // traverse on the right part of the tree
        TreeNode* lca2 = lowestCommonAncestor(root->right, p, q);         

        // second condition... (IF BOTH SUB-TREE CONTAINS 'p' & 'q' RESPECTIVELY)
        if(lca1 != NULL && lca2 != NULL) return root;                     
        // THIRD CONDITION...
        if(lca1 != NULL) return lca1;                                     
        // FOURTH CONDITION...
        return lca2;                                                      
    }
};

//Follow ups
//1. Find LCA of multiple nodes
class Solution {
    TreeNode* res;
    int helper(TreeNode* cur, unordered_set<TreeNode*>& st, int n) {
        if (!cur) return 0;
        int cnt = 0;
        cnt += helper(cur->left, st, n);
        cnt += helper(cur->right, st, n);
        if (st.find(cur) != st.end()) cnt++;
        if (cnt == n && !res) res = cur;
        return cnt;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> target) {
        res = NULL;
        unordered_set<TreeNode*> st;
        for (auto& t : target)
            st.insert(t);
        helper(root, st, target.size());
        return res;
    }
};
//2. Find path between p / q
def print_path(self, root, n1,n2):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        self.findLCA=False
    
        def dfs(node)://return path list if find n1 or n2.
            //if reach lca.end update path list.
            if not node:
                return []
            l=dfs(node.left)
            r=dfs(node.right)
            if self.findLCA: //if findLca, just return path to up and don't change it.
                return l or r
            if l and r://left and right has n1 and n2,node are lca
                self.findLCA = True
                return l + [node.val] + r[::-1]
            elif l or r:
                if node==n1 or node==n2:
                    self.findLCA=True
                    return l+[node.val]+r[::-1]
                else:
                    if l:
                        return l+[node.val]
                    else:
                        return r+[node.val]

            else://not l and not r
                if node==n1 or node==n2:
                    return [node.val]
                return []
        
        return dfs(root)

class Solution {
public:
    //TIME - O(N) SPACE - O(N)
    //TIME - O(N + N/2 + N/4 + N/8.....) = O(2*N)
    bool check(TreeNode* root,TreeNode* p){
        if(!root) return false;
        
        if(root == p) return true;
        
        return check(root->left,p) || check(root->right,p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        bool left_p = check(root->left,p);
        bool right_p = check(root->right,p);
        bool left_q = check(root->left,q);
        bool right_q = check(root->right,q);
        
        if((root == p && (left_q || right_q)) ||
           (root == q && (left_p || right_p)) ||
           (left_p && right_q) ||
           (left_q && right_p)) return root;
        
        if(left_p && left_q) return lowestCommonAncestor(root->left,p,q);
        
        return lowestCommonAncestor(root->right,p,q);
    }
};

class Solution {
public:
    bool check_tree(TreeNode* root, TreeNode* node){
        if(!root) return false;
        
        if(root == node) return true;
        return check_tree(root->left, node) || check_tree(root->right, node);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        if(p == root) return p;
        if(q == root) return q;
        
        bool p_left = check_tree(root->left,p);
        bool q_left = check_tree(root->left,q);
        
        if(p_left && q_left) return lowestCommonAncestor(root->left, p ,q);
        if(!p_left && !q_left) return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
};