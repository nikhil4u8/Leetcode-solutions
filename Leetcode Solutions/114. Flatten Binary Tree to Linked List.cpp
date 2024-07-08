/*
Ques to ask :
    - Tree Modification allowed or do we need to return copy of tree? 
        -> If allowed then use Morris traversal

Sol :
=> Preorder Traversal : [TIME - O(N) SPACE - O(N)]
    - Simply do a pre order traversal and store order in vector<TreeNode*> 
    & in end traverse that vector & link each node as right child of prev 
    node.

=> Using Recursion : [TIME - O(N) SPACE - O(N)]
    - First recursively flatten left & right subtree, then since it's 
    pre-order so DLR, so make 
    leftSubtree_lastNode->right = rightSubtree_head
    root->left = leftSubtree;

BEST APPROACH :
=> Using Morris traversal : [TIME - O(N) SPACE - O(1)]
    - The previous approach can be done in iterative format without stack.
    - Since it's preorder traversal i.e DLR, so first if left subtree exist 
    then find right most child of leftSubtree and link it to rightSubtree_head i.e
    right_most_child_leftSubtree->right = rightSubtree_Head;
    root->right = leftSubtree_Head;
    root->left = NULL;
    root = root->right;
    - Do same thing for every node until whole list if flatten
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        
        TreeNode* node = root;
        while(node){
            if(node->left){
                TreeNode* rightMost = node->left;
                while(rightMost->right) rightMost = rightMost->right;

                rightMost->right = node->right;
                node->right = node->left;
                node->left = NULL;
            }
            node = node->right;
        }
    }
};