/*
Ques to ask :
    - Can depth > depth of tree + 1
    - What depth the root had? depth = 0 or 1? In this ques root depth=1
    - What to do when depth = 1, when new root node comes, then which 
    subtree prev root node will belong to?

Sol :
WHY BFS ?
-> Since we have to change the links at some particular level so the 
very first thing that clicks to my mind is to used BFS. I just find it 
more intiuative.

BEST APPROACH
=> Using BFS : [TIME - O(N) SPACE - O(L) -> max nodes in a level]
    - Perform a BFS & decrement depth as we move to next level, do it 
    until we reach depth == 1 
    - At depth == 1, we've to add nodes, now we make new nodes and add 
    left subtree of current node to left of new node and right subtree of 
    current node to right of new node. Also, link new nodes as a child of 
    current node.
    - Once new nodes are linked break the loop & return root.

Edge case :
    - Depth = 1
*/
class Solution {
public:
//TIME - O(N) SPACE - O(L) -> max nodes in a level
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* temp = new TreeNode(val);
        if(depth == 1){
            temp->left = root;
            return temp;
        }

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty() && depth != 1){
            int size = q.size();
            depth--;
            while(size--){
                TreeNode* curr = q.front(); q.pop();
                
                if(depth == 1){
                    TreeNode* tempLeft = new TreeNode(val);
                    TreeNode* tempRight = new TreeNode(val);

                    tempLeft->left = curr->left;
                    tempRight->right = curr->right;

                    curr->left = tempLeft;
                    curr->right = tempRight;

                    continue;
                }

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }

        return root;
    }
};