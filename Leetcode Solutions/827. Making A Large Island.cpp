/*
Sol :
=> Converting every 0
    - Every 0 is a potential candidate for converting to 1, after converting
    every 0, we'll check what is the maximum size of island.

=> Painting Island then merging : [TIME - O(N*M) SPACE - O(N*M)]
    - In above approach, we'll converting every 0 is useless since if 
    they're not connected to island then it won't increase max island size
    so we'll convert only those 0 which are connected >= 1 island.
    - In general case, after converting '0' to '1' we'll just get prev 
    island size + 1 only. If we convert '0' connected to multiple 
    different island we can merge size island.
    - Traverse the grid & for each '1', we do DFS to paint different 
    connected components by different colors, we gonna paint in-place on 
    the grid matrix, so we start color from 2, because 0 and 1 is already 
    existed in the grid. 
    - Maintain a islandSizeMap to store mapping of size of connected 
    component to it's corresponding color
    - After marking all island with different index, now we traverse grid 
    & analyse all 0s in grid and merge all different directly connected 
    island with that '0' & summing up their sizes & updating largest 
    island size.
*/
class Solution {
public:
    vector<int>dir_x = {0,0,1,-1};
    vector<int>dir_y = {1,-1,0,0};
    unordered_map<int, int>islandSizeMap;
    int largestIslandSize = 0;
    //DFS method for traversing island and coloring it with islandNum
    void DFS(vector<vector<int>>&grid, int x, int y, int islandNum,int &islandSize){
        grid[x][y] = islandNum;
        islandSize++;

        for(int i=0;i<4;i++){
            int x0 = x + dir_x[i];
            int y0 = y + dir_y[i];

            if(x0 >= 0 && y0 >= 0 && x0 < grid.size() && y0 < grid[0].size() &&
            grid[x0][y0] == 1)
                DFS(grid, x0, y0, islandNum, islandSize);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islandNum = 2;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //if a island is found then mark it with a color
                if(grid[i][j] == 1){
                    int islandSize = 0;

                    DFS(grid, i, j, islandNum, islandSize);
                    
                    //updating largest island size & storing size in map
                    largestIslandSize = max(largestIslandSize, islandSize);
                    islandSizeMap[islandNum] = islandSize;
                    
                    islandNum++;
                }
            }
        }   
        //traversing all 0s
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    int mergesIslandSize = 1;
                    //used to avoid merging similar color island with 
                    //itself only different color island needs to be 
                    //merged & only their size needs to be added in 
                    //mergeIslandSize
                    unordered_set<int>visitedIsland;

                    for(int k=0;k<4;k++){
                        int x = i + dir_x[k];
                        int y = j + dir_y[k];

                        if(x >= 0 && y >= 0 && x < n && y < m && 
                           grid[x][y] != 0){
                           int tempIslandNum = grid[x][y];
                           //if same color island is found then skip
                           if(!visitedIsland.contains(tempIslandNum)){
                               //mark this as visited i.e size added in 
                               //mergeIslandSize
                               visitedIsland.insert(tempIslandNum);
                               //sum island size of different color
                               mergesIslandSize += islandSizeMap[tempIslandNum];
                           }
                        }
                    }
                    largestIslandSize = max(largestIslandSize, mergesIslandSize); 
                }
            }
        }

        return largestIslandSize;
    }
};