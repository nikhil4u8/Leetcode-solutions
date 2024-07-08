/*
Ques to ask :
    - What happens when we've 2 nodes at right side in same level? 
    Ex - [1,2,3,null,4,5,null], and will be [1,3,4] or [1,3,5]?

Sol :
BEST APPROACH
=> Level order traversal : [TIME - O(N) SPACE - O(W)]
    - Doing a level order traversal, and storing the last element of 
    each level in ans vector

Follow up :
    - Print left side of tree? 
        -> Push first element of each level in ans vector
*/

class Solution {
public:
//TIME - O(N) SPACE - O(W) -> queue
//W -> max nodes in a level
//N -> total nodes in a tree
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            TreeNode* lastNode = NULL;
            while(size--){
                TreeNode* curr = q.front(); q.pop();

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

                lastNode = curr;
            }
            ans.push_back(lastNode->val);
        }

        return ans;
    }
};
//RECURSIVE VERSION
//TIME - O(N) SPACE - O(Height)->recrusive stack
vector<int>res;
void view(TreeNode* root,int lev){
    if(lev==res.size()) res.push_back(root->val);
    
    if(root->right) view(root->right,lev+1);
    if(root->left) view(root->left,lev+1);
}
vector<int>rightSideView(TreeNode* root){
    if(!root) return res;
    view(root,0);
    return res;
}