/*
Ques to ask :
    - len of longest path is number of nodes in path or no. of edges?

Sol :
BEST APPROACH
=> Using DFS - [TIME - O(N) SPACE - O(N) -> recursive stack]
    - For every node, length of longest path which pass it is equal to 
    = MaxDepth of its left subtree + MaxDepth of its right subtree.
    - So we'll find len of longest path for all the nodes recrusively and 
    maintain maximum value among these path and return it.
*/
class Solution {
public:
//TIME - O(N) SPACE - O(N) -> recursive stack
    int maxDiameter = 0;
    int nodeDistanceFromRoot(TreeNode* root){
        if(!root) return 0;

        if(!root->left && !root->right) return 1;

        int leftDist = nodeDistanceFromRoot(root->left);
        int rightDist = nodeDistanceFromRoot(root->right);

        maxDiameter = max(maxDiameter, leftDist + rightDist + 1);

        return 1 + max(leftDist, rightDist);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        nodeDistanceFromRoot(root);
        return maxDiameter - 1;
    }
};