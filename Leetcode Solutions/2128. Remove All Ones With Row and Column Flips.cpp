//7:32
class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        for(int i=0;i<grid[0].size();i++){
            if(grid[0][i] == 1){
                //taking xor with "1" to flip col
                for(int j=1;j<grid.size();j++) 
                    grid[j][i] = grid[j][i] ^ 1; 
            }
        }
        
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[i].size();j++){
                if(grid[i][j] != grid[i][j-1])
                    return false;
            }
        }
        
        return true;
    }
};