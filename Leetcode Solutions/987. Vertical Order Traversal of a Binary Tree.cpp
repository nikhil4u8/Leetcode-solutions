/*
Ques to ask :-
    - How to arrange multiple nodes in same col / row
    - Multiple nodes in same col / row / same val?

Sol :-
SAY THIS FIRST
- Considering that tree is present in matrix & root = {0,0}, when we move 
to right child then it's coordinates are {row+1,col+1}, when move to left 
child then coordinates are {row+1, col-1}

=> Use Map & store mapping of {col -> {row, val}} : [TIME - O(Nlog(N/K)) SPACE - O(N)]
    - Simply do a tree traversal and store the nodes in a map which
    store mapping from {col -> {row, val}} & keep track of min / max col
    - In end traverse from min to max col & sort the vector present in 
    map[col] & store the sorted result in ans vector

BEST APPROACH
=> Using Level order traversal : [TIME - O(Nlog(N/K)) SPACE - O(N)]
    - Create a queue having a mapping of NODE -> {ROW, COL}
    - Create a map, which maps COL -> list of {row, node val}
    - Maintain min_width / max_width while doing BFS & add nodes in map 
    according to their col value.
    - At the end, traverse the map from left most to right most col & 
    add all elements in map to ans vector.

Follow up:
    - In same {row, col} sort it from right to left.
        -> Do BFS from right to left.
    - In same row, col sort it from left to right.
        -> Ref : 314 Binary tree vertical order traversal
    - In same row, col sort it by value
        -> Ref : 987 Vertical order traversal of a binary tree
*/
If node on same level then sort these nodes by their values.
class Solution {
public:
//TIME - O(Nlog(N/K)) SPACE - O(N)
/*
TIME - BFS/DFS takes O(N), since multiset is used for sorting K equal 
sized subgroups with total N elements in all, so time complexity of that 
will be  O(k * [N/k * log(N/k)]) = O(Nlog(N/K))
*/
    //BFS [Iterative approach]
    //TIME -  O(N*log(N/K)) SPACE - O(N)
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       if(!root) return {};
        unordered_map<int,vector<pair<int,int>>>mp;
        
        vector<vector<int>>res;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            int si = q.size();
            while(si--){
                auto temp = q.front();
                q.pop();

                mp[temp.second.second].push_back({temp.second.first,temp.first->val});
                
                mini = min(mini,temp.second.second);
                maxi = max(maxi,temp.second.second);
                
                if(temp.first->left) 
                    q.push({temp.first->left,{temp.second.first+1,temp.second.second-1}});
                if(temp.first->right)
                    q.push({temp.first->right,{temp.second.first+1,temp.second.second+1}});
            }
        }
        
        for(int i=mini;i<=maxi;i++){
            sort(mp[i].begin(),mp[i].end());
            for(int j=0;j<mp[i].size();j++){
                res[i].push_back(mp[i][j].second);
            }
        }
    }

    //TIME - O(Nlog(N/K)) or say O(NlogN)
    //SPACE - O(N)
    unordered_map<int, vector<pair<int, int>>>mp;
    int minCol = INT_MAX, maxCol = INT_MIN;
    void inorderTraversal(TreeNode* root, int row, int col){//TIME - O(N)
        if(!root) return;

        inorderTraversal(root->left, row+1, col-1);
        
        mp[col].push_back({row, root->val});
        minCol = min(minCol, col);
        maxCol = max(maxCol, col);

        inorderTraversal(root->right, row+1, col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        inorderTraversal(root, 0, 0); //O(N)
        
        vector<vector<int>>ans;
        for(int i = minCol; i<=maxCol; i++){//O((N/K)*log(N/K))
            sort(mp[i].begin(), mp[i].end());
            vector<int>temp;

            for(int j=0;j<mp[i].size();j++)
                temp.push_back(mp[i][j].second);

            ans.push_back(temp);
        }

        return ans;
    }
};