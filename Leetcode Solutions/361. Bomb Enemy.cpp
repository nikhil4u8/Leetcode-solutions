class Solution {
public:
//TIME - O(N*M) SPACE - O(N*M)
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int maxi = 0, n = grid.size(), m = grid[0].size();
        vector<vector<int>>bomb(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++){
            int temp_bomb = 0;
            for(int j=0;j<m;j++){
                if(grid[i][j] == 'E') temp_bomb++;
                else if(grid[i][j] == 'W') temp_bomb = 0;
                else bomb[i][j] += temp_bomb;
            }
            
            temp_bomb = 0;
            
            for(int j=m-1;j>=0;j--){
                if(grid[i][j] == 'E') temp_bomb++;
                else if(grid[i][j] == 'W') temp_bomb = 0;
                else bomb[i][j] += temp_bomb;
            }
        }
        
        for(int i=0;i<m;i++){
            int temp_bomb = 0;
            for(int j=0;j<n;j++){
                if(grid[j][i] == 'E') temp_bomb++;
                else if(grid[j][i] == 'W') temp_bomb = 0;
                else bomb[j][i] += temp_bomb;
            }
            
            temp_bomb = 0;
            
            for(int j=n-1;j>=0;j--){
                if(grid[j][i] == 'E') temp_bomb++;
                else if(grid[j][i] == 'W') temp_bomb = 0;
                else{
                    bomb[j][i] += temp_bomb;
                    maxi = max(maxi, bomb[j][i]);
                }
            }
        }
        
        return maxi;
    }
};
