/*
Ques to ask :
    - Any specific order in which output is returned?

Sol :
=> Tree Traversal while tracking path until curr node 
-> [TIME - O(N) SPACE - O(N) -> recursive stack]
*/
class Solution {
public:
    vector<string>ans;
    void rootToLeafPath(TreeNode* root, string path){
        if(!root) return;

        if(!root->left && !root->right){
            path += to_string(root->val);
            ans.push_back(path);
            return;
        }

        path += to_string(root->val) + "->";

        rootToLeafPath(root->left, path);
        rootToLeafPath(root->right, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        rootToLeafPath(root, "");

        return ans;
    }
};