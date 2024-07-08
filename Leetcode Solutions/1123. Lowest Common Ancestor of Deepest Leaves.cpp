/*
Ques to ask:
    - What if there is only one node which is deepest?

Sol :
=> Two pass sol : [TIME - O(N) SPACE - O(N) -> map space]
    - For each node in a tree, we need to keep track of depth of deepest 
    node in left subtree and right subtree & store these depth in a map
    - Once we precompute all the depth of left / right subtree for each 
    node, then traverse again & use map to find that for curr node if 
    depth of deepest node in left subtree == depth of deepest node in 
    right subtree then curr node is LCA, otherwise move towards the 
    subtree having more depth of deepest node.


BEST APPROACH
=> One pass sol : [TIME - O(N) SPACE - O(N) -> recursive stack]
    - The idea is to calculate the depth on left and right side for each 
    node also going down keep track the max depth, now for each node get 
    left and right depth if both depth are same and they are same with 
    max depth then consider the current node as LCA and return max of 
    left and right depth for each node.

Follow up : 
    - What if tree doesn't contain p / q ? 
        -> before recursion check if P/Q are present, if not present then 
        return Null, otherwise recrusion
        -> 1644. Lowest Common Ancestor of a Binary Tree II
        
Similar ques : 
    - Ref 236. Lowest Common Ancestor of a Binary Tree
    - Ref 1123. Lowest Common Ancestor of Deepest Leaves
    - Ref 1650. Lowest Common Ancestor of a Binary Tree III
    - Ref 235. Lowest Common Ancestor of a Binary Search Tree
    - Ref 1644. Lowest Common Ancestor of a Binary Tree II
*/
class Solution {
public:
//BEST APPROACH
//Approach - 2
//TIME - O(N) SPACE - O(1)
    int maxDepth = 0;
    TreeNode* lca = NULL;
    int solve(TreeNode* root, int depth){
        maxDepth = max(maxDepth, depth);
        if(!root) return depth;

        int leftSubtreeDepth = solve(root->left, depth + 1);
        int rightSubtreeDepth = solve(root->right, depth + 1);

        if(leftSubtreeDepth == rightSubtreeDepth && 
            rightSubtreeDepth == maxDepth) lca = root;

        return max(leftSubtreeDepth, rightSubtreeDepth);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        solve(root, 0);
        return lca;
    }
//Approach - 1
    unordered_map<TreeNode*, pair<int, int>>mp;
    //use to precompute & store depth of deepest node of left / right 
    //subtree. It's done for every node in tree
    pair<int, int> storeDepthOfNode(TreeNode* root){
        if(!root) return {-1, -1};

        if(!root->left && !root->right) return {0, 0};

        //depth of deepest node left / right subtree
        pair<int, int> leftSubtree = storeDepthOfNode(root->left);
        pair<int, int> rightSubtree = storeDepthOfNode(root->right);

        //max(depth of node in left subtree), max(depth of node in right 
        //subtree)
        pair<int, int> currNodeDepth = {1 + max(leftSubtree.first, leftSubtree.second), 1 + max(rightSubtree.first, rightSubtree.second)};

        //store it in map
        mp[root] = currNodeDepth;
        return currNodeDepth;
    }
    //Find LCA based on the depth stored in map
    TreeNode* findLCA(TreeNode* root){
        if(!root) return NULL;

        pair<int, int> rootNodeDepth = mp[root];
        
        //if depth in left / right subtree is same then LCA = root
        //otherwise move towards the subtree who has deepest node
        if(rootNodeDepth.first == rootNodeDepth.second) return root;
        else if(rootNodeDepth.first > rootNodeDepth.second) root = root->left;
        else root = root->right;

        return findLCA(root);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return NULL;

        //precomputing depth
        storeDepthOfNode(root);
        //finding LCA
        return findLCA(root);
    }
};