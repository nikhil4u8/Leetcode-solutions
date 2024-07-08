class Solution {
public:
    int dir_x[4] = {0,0,1,-1};
    int dir_y[4] = {1,-1,0,0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        if(n == 0) return {};
        
        int m = heights[0].size();
        
        vector<vector<bool>>pacific(n, vector<bool>(m, false));
        vector<vector<bool>>atlantic(n, vector<bool>(m, false));
        
        queue<pair<int,int>>pac;
        for(int i=1;i<n;i++){
            pac.push({i,0});
            pacific[i][0] = true;
        }
        for(int i=1;i<m;i++){
            pac.push({0,i});
            pacific[0][i] = true;
        }
        
        pac.push({0,0});
        pacific[0][0] = true;
        
        while(!pac.empty()){
            auto temp = pac.front(); pac.pop();
            int x = temp.first;
            int y = temp.second;
            
            for(int i=0;i<4;i++){
                int x0 = x + dir_x[i];
                int y0 = y + dir_y[i];
                
                if(x0>=0 && y0>=0 && x0<n && y0<m && heights[x0][y0] >= heights[x][y] && !pacific[x0][y0]){
                    pacific[x0][y0] = true;
                    pac.push({x0,y0});
                }
            }
        }
        
        queue<pair<int,int>>atl;
        for(int i=0;i<n-1;i++){
            atl.push({i,m-1});
            atlantic[i][m-1] = true;
        }
        for(int i=0;i<m-1;i++){
            atl.push({n-1,i});
            atlantic[n-1][i] = true;
        }
        
        atl.push({n-1,m-1});
        atlantic[n-1][m-1] = true;
        
        while(!atl.empty()){
            auto temp = atl.front(); atl.pop();
            int x = temp.first;
            int y = temp.second;
            
            for(int i=0;i<4;i++){
                int x0 = x + dir_x[i];
                int y0 = y + dir_y[i];
                
                if(x0>=0 && y0>=0 && x0<n && y0<m && heights[x0][y0] >= heights[x][y] && !atlantic[x0][y0]){
                    atlantic[x0][y0] = true;
                    atl.push({x0,y0});
                }
            }
        }
        
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic[i][j] && pacific[i][j]) ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};