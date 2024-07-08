/*
Ques to ask:
    - What to return when path doesn't exist?

Sol :
=> Using DFS : [TIME - O()]
    - count number of visited nodes in a clear path using DFS & in end 
    find the min.

BEST APPROACH
=> Usinf BFS : [TIME - O(N) SPACE - O(N)]
->  N : number of cells in the grid.
    - We'll use BFS to find the shortest path instead of using DFS for 
    better time complexity.
    - In DFS, it explore every possible path until end then it'll judge 
    if it's best or not. Shortest path here is determined only after 
    exploring all possible paths.
    - In BFS, it explore all the path simultaneously, since it works on 
    level basis, so the path which first reaches the end has the shortest 
    path, here we're not traversing until every path reaches end, we're 
    terminating when we find first path who reached end.

Edge Case :
    - When start / end point is 1.
    - When matrix has one row, one col.
    
Follow up :
    - Find all path from source to dest in binary matrix?
        -> In DFS keep track of path vector.
*/
class Solution {
public:
//BEST APPROACH
//BFS : TIME - O(N) SPACE - O(N)
    vector<int>dir_x = {1,1,-1,-1,0,0,1,-1};
    vector<int>dir_y = {1,-1,1,-1,1,-1,0,0};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         int n = grid.size(); 
        if(n == 0) return -1;

        int m = grid[0].size();
        
        if(grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;

        int steps = 0;
        queue<pair<int, int>>q;

        q.push({0, 0});
        grid[0][0] = 2;
        steps++;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto currNode = q.front(); q.pop();
                int x = currNode.first, y = currNode.second;
                //reached end so return step
                if(x == n-1 && y == m-1) return steps;

                for(int i=0;i<8;i++){
                    int x0 = x + dir_x[i];
                    int y0 = y + dir_y[i];

                    //check if next block is 0 or not
                    if(x0 >= 0 && y0 >= 0 && x0 < n && y0 < m && 
                       grid[x0][y0] == 0){
                           //if next block is end then return right now
                           //instead of processing queue until we reach
                           //this element
                           if(x0 == n-1 && y0 == m-1) return steps + 1;
                           grid[x0][y0] = 2;
                           q.push({x0, y0});
                       }
                }
            }

            steps++;
        }

        return -1;
    }
//APPROACH 1 - DFS
//DFS : NOT best for shortest path
    int minClearPathLen = INT_MAX;
    void findPath(vector<vector<int>>&grid, int x, int y, int pathLen){
        if(x == grid.size()-1 && y == grid[0].size()-1){
            minClearPathLen = min(minClearPathLen, pathLen);
            return;
        }

        for(int i=0;i<8;i++){
            int x0 = x + dir_x[i];
            int y0 = y + dir_y[i];

            if(x0 >= 0 && y0 >= 0 && x0 < grid.size() && y0 < grid[0].size() &&
            grid[x0][y0] == 0){
                grid[x0][y0] = 2;
                findPath(grid, x0, y0, pathLen + 1);
                grid[x0][y0] = 0;
            }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); 
        if(n == 0) return -1;

        int m = grid[0].size();
        
        if(grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;

        grid[0][0] = 2;
        findPath(grid, 0, 0, 1);
        return minClearPathLen == INT_MAX ? -1 : minClearPathLen;
    }  
};