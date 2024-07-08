class Solution {
public:
    //TIME - O(N*M) SPACE - O(N*M)
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        
        int ans = 0;
        int dir_x[4] = {0,0,1,-1};
        int dir_y[4] = {1,-1,0,0};
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int x0 = x + dir_x[i];
                    int y0 = y + dir_y[i];
                    
                    if(x0>=0 && y0>=0 && x0<n && y0<m && grid[x0][y0]==1){
                        q.push({x0,y0});
                        grid[x0][y0] = 2;
                    }
                }
            }
            if(!q.empty()) ans++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }        
        return ans;
    }
    //FOLLOW-UP
    //DO IT IN-PLACE
    //TIME - O(N*M*N*M) SPACE - O(1)
    bool check_if_fresh_tomato_left(int num,vector<vector<int>>&grid,int n,int m){
        bool flag = false;
        int dir_x[4] = {0,0,1,-1};
        int dir_y[4] = {1,-1,0,0};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == num){
                    for(int k=0;k<4;k++){
                        int x = i + dir_x[k];
                        int y = j + dir_y[k];
                        
                        if(x>=0 && y>=0 && x<n && y<m && grid[x][y] == 1){
                            grid[x][y] = num + 1;
                            flag = true;
                        }
                    }
                }
            }
        }
        
        return flag;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int maxi = 2;
        
        while(check_if_fresh_tomato_left(maxi,grid,n,m))
            maxi++;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        
        return maxi-2;
    }
};