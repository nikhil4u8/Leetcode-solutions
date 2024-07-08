/*
Ques to ask:
    - What's range of num formed in end, will it go out of range of int? 
    - Can a node contain a number of more than one digit?

Sol :
BEST APPROACH
=> Using BFS : [TIME - O(N) SPACE - O(L) -> L is max nodes in a level]
    - Using BFS, traverse from root to leaf node while storing the number 
    formed from root -> node in the queue, when we reach leaf node, then 
    adding the number formed to ans.
*/
class Solution {
public:
//TIME - O(N) SPACE - O(L) -> L is max nodes in a level
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, root->val});

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr = q.front(); q.pop();
                TreeNode* currNode = curr.first;
                int val = curr.second;

                if(!currNode->left && !currNode->right) sum += val;

                if(currNode->left) 
                    q.push({currNode->left, val*10 + currNode->left->val});
                if(currNode->right) 
                    q.push({currNode->right, val*10 + currNode->right->val});
            }
        }

        return sum;
    }
};