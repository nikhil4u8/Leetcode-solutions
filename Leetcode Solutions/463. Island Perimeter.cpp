class Solution {
public:
    //time - o(n*m)
    int xx[4] = {0,0,1,-1};
    int yy[4] = {1,-1,0,0};
    void DFS(vector<vector<int>>&grid,vector<vector<bool>>&visited,int x,int y,int n,int m,int &a){
        
        visited[x][y] = true;
        a += 4;
        
        for(int i=0;i<4;i++){
            int x0 = x + xx[i];
            int y0 = y + yy[i];
            if(x0>=0 && y0>=0 && x0<n && y0<m && grid[x0][y0]==1){
                a--;
                if(!visited[x0][y0])
                    DFS(grid,visited,x0,y0,n,m,a);
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        int area = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(!visited[i][j] && grid[i][j]==1)
                    DFS(grid,visited,i,j,n,m,area);
            }
        }
        
        return area;
    }
};
//Approach-2 (BFS)
class Solution {
public:
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int perimeter = 0;
        
        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = -1;
        while(!que.empty()) {
            auto it = que.front();
            que.pop();
            
            for(pair<int, int> &p : directions) {
                int i_ = it.first  + p.first;
                int j_ = it.second + p.second;
                
                if(i_ < 0 || i_ >= grid.size() || j_ < 0 || j_ >= grid[0].size() || grid[i_][j_] == 0)
                    perimeter++;
                else if(grid[i_][j_] == -1) {
                    continue;
                } else {
                    que.push({i_, j_});
                    grid[i_][j_] = -1;
                }
            }
        }
        
        return perimeter;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    return bfs(grid, i, j);
                }
            }
        }
        
        return 0;
    }
};


//Approach-3 (Iterative)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int perimeter = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 0)
                    continue;
                
                if(i-1 < 0 || grid[i-1][j] == 0) //up
                    perimeter++;
                
                if(i+1 >= m || grid[i+1][j] == 0) //down
                    perimeter++;
                
                if(j-1 < 0 || grid[i][j-1] == 0) //left
                    perimeter++;
                
                if(j+1 >= n || grid[i][j+1] == 0) //right
                    perimeter++;
                
            }
        }
        
        return perimeter;
    }
};