/*
Sol :
BEST APPROACH
=> BFS : [TIME - O(N) SPACE - O(N)]
    - Do a BFS using a queue, put child of nodes in the queue & keep track 
    when a null node is found, once a null is found nodes after that must 
    be null too, if found a non null node then return false.
*/
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool nullFound = false;
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();

            if(curr == NULL) nullFound = true;
            else{
                if(nullFound) return false;

                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return true;
    }
};