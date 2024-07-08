/*
Sol :
=> Using DFS : [TIME - O(N*M) SPACE - O(N*M) -> recursive stack]
    - The idea is to count the area of each island using dfs. During the 
    dfs, we set the value of each point in the island to 0.
*/
class Solution {
public: 
    vector<int>dir_x = {0,0,1,-1};
    vector<int>dir_y = {1,-1,0,0};
    void DFS(vector<vector<int>>&grid, int x, int y, int &islandSize){
        grid[x][y] = -1;
        islandSize++;

        for(int i=0;i<4;i++){
            int x0 = x + dir_x[i];
            int y0 = y + dir_y[i];

            if(x0 >= 0 && y0 >= 0 && x0 < grid.size() & y0 < grid[0].size() &&
                grid[x0][y0] == 1)
                DFS(grid, x0, y0, islandSize);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, n = grid.size(), m = grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int islandSize = 0;
                    DFS(grid, i, j, islandSize);
                    maxArea = max(maxArea, islandSize);
                }
            }
        }

        return maxArea;
    }
};