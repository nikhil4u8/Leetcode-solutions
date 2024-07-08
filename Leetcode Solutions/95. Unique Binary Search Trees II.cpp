/*
Sol :
BEST APPROACH
=> Using Recursion : TC - see below
    - We've to form a BST using numbers from 1 - N, so if we consider 
    every node (ith node) as a root node, then it's left subtree will be 
    formed of [1..i-1] and right subtree will be formed of [i+1...n], so 
    we'll recursively build a array of all the valid combination of left 
    / right subtree & then combine different pairs of {left subtree, right 
    subtree} with root node & insert it into ans array.
*/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n, int start = 1) {
        int end = n;
        if(start > end) return {NULL};
        if(start == end) return {new TreeNode(start)};

        vector<TreeNode*>ans;

        for(int i=start;i<=n;i++){
            vector<TreeNode*> leftSubtree = generateTrees(i-1, start);
            vector<TreeNode*> rightSubtree = generateTrees(end, i+1);

            for(int j=0;j<leftSubtree.size();j++){
                for(int k=0;k<rightSubtree.size();k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftSubtree[j];
                    root->right = rightSubtree[k];
                    
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
};
/*
T(N) = T(1)*T(N-2) + T(2)*T(N-3) + T(3)*T(N-4) + ... T(N-2)*T(1)
= sum of[T(k)*T(N-1-k)] from k = 1 - (N-2)
= Catlan number [C(n) = 2n!/((n+1)!*n!)]
= 2(n-2)! / ((n-1)!*(n-2)!)

SC : Exponential
*/