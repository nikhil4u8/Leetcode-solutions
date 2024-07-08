/*
Desc : Find unique path to reach from (0,0) to (n-1, m-1) without obstacle
Similar Ques : 
    - Find unique path without obstacle 
        -> Ref : 62. Unique Paths
    - Find unique path with obstacles
        -> Ref 63. Unique Paths II
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++) grid[i][0] = 1;
        for(int i=0;i<n;i++) grid[0][i] = 1;
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++)
                grid[i][j] = grid[i][j-1] + grid[i-1][j];
        }
        
        return grid[m-1][n-1];
    }
};