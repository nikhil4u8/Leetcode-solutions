/*
Ques to node :
    - Does it needs to be a full binary tree (each node will have either 
    0 / 2 child)?
    - What will be the value of the node?

Sol :
=> Naive - Recursion : [TIME - O(N!) SPACE - O(N!)]
    - N will be full binary tree if N is an odd number.
    - Since generating a subtree with N-1 nodes, will be a same problem 
    as generating tree with N nodes, just different N, so we'll use 
    recursion.
    - To make a binary tree, a subtree can have [1,3,5...N-1] nodes, so 
    we'll generate a array of root node of all possible left subtree with 
    i nodes & a array of root node of all possible right subtree with 
    N-1-i nodes.
    - Combine all left subtree with right subtree & add the resultant root 
    node in array.

=> Recursion + Memo : [TIME - O(2^N) SPACE - O(2^N)]
    - We can use a map to record solution for different N

Edge case :
    - When N is even or N == 1
*/
class Solution {
public:
    unordered_map<int, vector<TreeNode*>>mp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0) return mp[n] = {};
        if(n == 1) return mp[n] = {new TreeNode(0)};

        if(mp.find(n) != mp.end()) return mp[n];

        vector<TreeNode*>ans;

        for(int i = 1;i<n-1;i+=2){
            //finding left / right subtree combinations
            vector<TreeNode*> leftSubtree = allPossibleFBT(i);
            vector<TreeNode*> rightSubtree = allPossibleFBT(n-1-i);

            for(int j=0;j<leftSubtree.size();j++){
                for(int k=0;k<rightSubtree.size();k++){
                    //creating root node & combining it with all left
                    //&right subtree
                    TreeNode* root = new TreeNode(0);
                    root->left = leftSubtree[j];
                    root->right = rightSubtree[k];

                    ans.push_back(root);
                }
            }
        }

        return mp[n] = ans;
    }
};