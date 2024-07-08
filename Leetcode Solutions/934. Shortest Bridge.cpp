class Solution {
public:
    queue<pair<int, int>>q;
    int dirx[4] = {1,-1,0,0};
    int diry[4] = {0,0,1,-1};
    void DFS(vector<vector<int>>&grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return;
        
        bool is_corner = false;
        grid[i][j] = 2;
        
        for(int k=0;k<4;k++){
            int x0 = i + dirx[k];
            int y0 = j + diry[k];
            
            if(x0>=0 && y0>=0 && x0<grid.size() && y0<grid[0].size()){
                if(grid[x0][y0] == 0) is_corner = true;
                if(grid[x0][y0] == 1) DFS(grid, x0, y0);
            }
        }
        
        
        if(is_corner) q.push({i, j});
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            bool out = false;
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    DFS(grid, i, j);
                    out = true;
                    break;
                }
            }
            if(out) break;
        }
        
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            steps--;
            while(size--){
                auto temp = q.front();
                q.pop();
                
                for(int i=0;i<4;i++){
                    int x0 = temp.first + dirx[i];
                    int y0 = temp.second + diry[i];
                    
                    if(x0>=0 && y0>=0 && x0<grid.size() && y0<grid[0].size()){
                        if(grid[x0][y0] == 0){
                            grid[x0][y0] = steps;
                            q.push({x0, y0});   
                        }else if(grid[x0][y0] == 1) return abs(steps)-1;
                    }
                }
            }
        }
        
        return -1;
    }
};