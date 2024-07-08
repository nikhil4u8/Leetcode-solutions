/*
Ques to ask :
    - Is tree a BST?

Sol :
=> Sorting Vector : [TIME - O((N+M)log(N+M)) SPACE - O(N+M)]
    - Traverse both tree & store all number in a single vector then sort 
    the vector

BEST APPROACH
=> Merging vector : [TIME - O(N+M) SPACE - O(N+M)]
    - Instead of sorting the vector, Traverse each tree, using inorder 
    traversal, in this way for BST result will be sorted list.
    - After traversing both the vector, use 2 pointer to merge both vector 
    into single one
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(N+M) SPACE - O(N+M)
    vector<int> treeTraversal(TreeNode* root){
        if(!root) return {};

        if(!root->left && !root->right) return {root->val};
        
        vector<int>left, right;

        left = treeTraversal(root->left);
        right = treeTraversal(root->right);

        left.push_back(root->val);
        left.insert(left.end(), right.begin(), right.end());

        return left;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        //sorted list of numbers in tree
        vector<int>tree1 = treeTraversal(root1);
        vector<int>tree2 = treeTraversal(root2);

        vector<int>ans;
        int i = 0, j = 0, n = tree1.size(), m = tree2.size();

        //merging both list
        while(i<n || j<m){
            int curr = -1;
            if(i >= n) curr = tree2[j++];
            else if(j >= m) curr = tree1[i++];
            else if(tree1[i] < tree2[j]) curr = tree1[i++];
            else curr = tree2[j++];

            ans.push_back(curr);
        }  

        return ans;
    }
};