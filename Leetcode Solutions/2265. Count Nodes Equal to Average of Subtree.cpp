/*
Ques to ask :
    - What if avg is fractional?

Sol :
=> Tree Traversal for each node : [TIME - O(N^2) SPACE - O(N) -> recursive stack]
    - Iterate the whole tree for every node, to find it's sum & maintain a 
    count variable to store total number of nodes under curr node & 
    calculate avg & check if it's equal to root->val, if it is then 
    incremenet ans.

BEST APPROACH
=> Single tree traversal : [TIME - O(N) SPACE - O(N) -> recursive stack]
    - Since we're going through same tree again & again & recomputing 
    everything for each node, instead we'll can do a single traversal & 
    recursively calculate sum of nodes in left / right subtree & return 
    it along with number of nodes in left / right subtree, this data will 
    be used to find avg for every node, if avg == root->val then increment 
    ans
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(N) SPACE - O(N) -> recursive stack
    int count = 0;
    pair<int, int> treeTraversal(TreeNode* root){
        if(!root) return {0, 0};

        int sum = root->val, totalNodes = 1;
        
        //finding {sum, totalnodes} in left / right subtree
        pair<int, int> leftSubtree = treeTraversal(root->left);
        pair<int, int> rightSubtree = treeTraversal(root->right);
        
        totalNodes += leftSubtree.second + rightSubtree.second;
        sum += leftSubtree.first + rightSubtree.first;

        int avg = sum / totalNodes;

        if(avg == root->val) count++;
        return {sum, totalNodes};
    }
    int averageOfSubtree(TreeNode* root) {
        treeTraversal(root);
        return count;
    }
};