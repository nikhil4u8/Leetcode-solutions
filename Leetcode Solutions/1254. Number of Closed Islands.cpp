class Solution {
public:
//TIME - O(N*M) SPACE - O(1)
    int xx[4] = {0,0,1,-1};
    int yy[4] = {1,-1,0,0};
    bool DFS(vector<vector<int>>&grid,vector<vector<bool>>&visited,int x,int y){
        visited[x][y] = true;
        bool ans = true;
        for(int i=0;i<4;i++){
            int x0 = x + xx[i];
            int y0 = y + yy[i];
            if(x0>=0 && y0>=0 && x0<grid.size() && y0<grid[0].size() && 
                !visited[x0][y0] && grid[x0][y0]==0){
                if(x0==0 || y0==0 || x0==grid.size()-1 || y0==grid[0].size()-1) ans = false;
                ans = ans & DFS(grid,visited,x0,y0);
            }
        }
        
        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size(),m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
      
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!visited[i][j] && grid[i][j]==0)
                    if(DFS(grid,visited,i,j)) res++;
            }
        }
        
        return res;
    }
};