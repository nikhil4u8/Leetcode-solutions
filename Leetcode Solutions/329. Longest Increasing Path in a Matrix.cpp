/*
Ques to ask : 
    - Can equal element become part of sequence?

Sol : 
=> Recursive Brute force : [TIME - O(N*M*4^(N*M)) SPACE - O(N*M)]
    - For each cell, using DFS we'll find the len of longest path by going in 
    all 4 direction st next element > current element

=> Recursive with memoziation : [TIME - O(NM) SPACE - O(NM)]
    - In prev approach we noticed that there are many path which are recalculated, 
    so we'll create a array for memoziation to store already processed states.

BEST APPROACH
=> Outdegree Approach : [TIME - O(NM) SPACE - O(NM)]
    - If we see, this matrix is a directed graph, so if we calculate outdegree 
    of every cell, then the cell having largest value will have outdegree = 0 
    i.e they're the end point of a increasing sequence.
    - We'll store all node with outdegree = 0 in queue and  start doing a 
    backward BFS traversal (in decreasing manner) until we reach starting point 
    of increasing sequence, and we'll maintain longest len in this process & 
    return it.

Follow up : 
    - Print path of increasing seq?
        -> It's better if we do DFS to find path, in BFS it become complicated.
*/
class Solution {
public:
    vector<int>dir_x = {0,0,1,-1};
    vector<int>dir_y = {1,-1,0,0};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();

        vector<vector<int>>outdegree(n, vector<int>(m, 0));
        queue<pair<int, int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    int x = i + dir_x[k];
                    int y = j + dir_y[k];

                    if(x>=0 && y>=0 && x<n && y<m && matrix[i][j] < matrix[x][y])
                        outdegree[i][j]++;
                }

                //if outdegree = 0 i.e endpoint of a seq
                if(outdegree[i][j] == 0) q.push({i, j});
            }
        }

        int longestPathLen = 0;

        //Backward BFS traversal for every endPoint
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr = q.front(); q.pop();
                int x = curr.first;
                int y = curr.second;

                for(int i=0;i<4;i++){
                    int x0 = x + dir_x[i];
                    int y0 = y + dir_y[i];

                    //if next node is smaller than current one then decrease it's outdegree until it become 0 i.e until the node become endPoint of a seq then push it queue
                    if(x0 >= 0 && y0 >= 0 && x0 < n && y0 < m &&
                    matrix[x0][y0] < matrix[x][y]){
                        outdegree[x0][y0]--;
                        if(outdegree[x0][y0] == 0)
                            q.push({x0, y0});
                    }
                }
            }
            longestPathLen++;
        }

        return longestPathLen;
    }
    //Using DFS + Memo
    //TIME - O(mn), since Each vertex/cell will be calculated once and only once, and each edge will be visited once and only once
    //Space complexity : O(mn) The cache dominates the space complexity.
    int dir_x[4] = {0,0,1,-1};
    int dir_y[4] = {1,-1,0,0};
    vector<vector<int>>cache = vector<vector<int>>(201, vector<int>(201, -1));
    int DFS(vector<vector<int>>&matrix, int x, int y){
        if(cache[x][y] != -1) return cache[x][y];
        int ans = 0;
        for(int i=0;i<4;i++){
            int x0 = x + dir_x[i];
            int y0 = y + dir_y[i];
            
            if(x0>=0 && y0>=0 && x0<matrix.size() && y0<matrix[0].size() && matrix[x][y]<matrix[x0][y0])
                ans = max(ans, DFS(matrix, x0, y0));
        }
        
        return cache[x][y] = ans + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans, DFS(matrix, i, j));
            }
        }
        
        return ans;
    }
};