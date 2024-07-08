/*
Ques to ask :-
    - How to arrange nodes in same level?
    - In a col, do we need to grp nodes from top to bottom?

Sol :-
INITALLY SAY THIS
If we consider tree as a matrix st each node has {row, col} val then in 
level order traversal, we grouped all nodes who have same row, here we've 
to group nodes who have same col.

BEST APPROACH
=> Using Level order traversal : [TIME - O(N) SPACE - O(N)]
    - Col of left child = parent_col - 1, Col right child = parent_col + 1
    - Create a queue having a mapping of COL -> list of NODE
    - Create a map, which maps NODES into different COL bucket
    - Maintain min_width / max_width while doing BFS & add nodes in map 
    according to their col value.
    - At the end, traverse the map from left most to right most col & 
    add all elements in map to ans vector.


NOTE : 
    - If the tree is balanced, use DFS or BFS
    - If not balanced, use BFS, because DFS use bigger stack, and 
    preallocated 2D matrix will have many entries empty (I am not 
    talking about your solution, I am talking about others' solution).

Follow up:
    - In same {row, col} sort it from right to left.
        -> Do BFS from right to left.
    - In same {row, col} sort it from left to right.
        -> Ref : 314 Binary tree vertical order traversal
    - In same {row, col} sort it by value
        -> Ref : 987 Vertical order traversal of a binary tree
*/
If two nodes are in the same row and column, the order should be from left to right.
class Solution {
public:
//BEST APPROACH
    //BFS
    //TIME - O(N) SPACE - O(N)
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        //width -> [nodes]
        unordered_map<int, vector<int>>mp; //SPACE - O(N)
        //{node, width}
        queue<pair<TreeNode*, int>>q; //SPACE - O(max nodes in a level)
        int max_width = INT_MIN, min_width = INT_MAX;

        q.push({root, 0});

        while(!q.empty()){ //TIME - O(N)
            int size = q.size();
            while(size--){
                pair<TreeNode*, int> curr = q.front(); q.pop();
                
                //Since BFS is already in increasing height, so we just 
                //have to arrange elements as per their width, in height 
                //they're automatically arranged.
                mp[curr.second].push_back(curr.first->val);

                max_width = max(max_width, curr.second);
                min_width = min(min_width, curr.second);

                if(curr.first->left) q.push({curr.first->left, curr.second-1});
                if(curr.first->right) q.push({curr.first->right, curr.second+1});
            }
        }

        vector<vector<int>>ans;

        for(int i=min_width;i<=max_width;i++) ans.push_back(mp[i]);

        return ans;
    }
};