//TIME - O(N^2) SPACE - O(N^2)
class Solution {
public:
    vector<int>dir_x = {1,-1,0,0};
    vector<int>dir_y = {0,0,1,-1};
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        int steps = 0;

        queue<pair<int, int>>q;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1) q.push({i, j});
            }
        }

        while(!q.empty()){
            int size = q.size();
            steps++;

            while(size--){
                auto curr = q.front(); q.pop();
                int x = curr.first;
                int y = curr.second;

                for(int i=0;i<4;i++){
                    int x0 = x + dir_x[i];
                    int y0 = y + dir_y[i];

                    if(x0>=0 && y0>=0 && x0<n && y0<m && grid[x0][y0] != 1 && !visited[x0][y0]){
                        visited[x0][y0] = true;
                        grid[x0][y0] = -steps;
                        q.push({x0, y0});
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j] != 1) ans = min(ans, grid[i][j]);
        }

        if(ans == 0) return -1;

        return abs(ans);
    }

    //Using DP
    //TIME - O(N^2) SPACE - O(N^2)
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), MAX_DISTANCE = rows + cols + 1;
        vector<vector<int>> dist(rows, vector<int> (cols, MAX_DISTANCE));
    
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Distance of land cells will be 0.
                if (grid[i][j]) dist[i][j] = 0;
                else
                    // Check left and top cell distances if they exist and update the current cell distance.
                    dist[i][j] = min(dist[i][j], min(i > 0 ? dist[i - 1][j] + 1 : MAX_DISTANCE,
                                                     j > 0 ? dist[i][j - 1] + 1 : MAX_DISTANCE));
            }
        }
        // Second pass: check for right and bottom neighbours.
        int ans = INT_MIN;
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                // Check the right and bottom cell distances if they exist and update the current cell distance.
                dist[i][j] = min(dist[i][j], min(i < rows - 1 ? dist[i + 1][j] + 1 : MAX_DISTANCE,
                                                 j < cols - 1 ? dist[i][j + 1] + 1 : MAX_DISTANCE));
                ans = max(ans, dist[i][j]);
            }
        }
        // If ans is 0, it means there is no water cell,
        // If ans is MAX_DISTANCE, it implies no land cell.
        return ans == 0 || ans == MAX_DISTANCE ? -1 : ans;
    }
};