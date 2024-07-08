/*
Ques to ask : 
    - Can we build a house on multiple 0s or single 0s?
        -> single 0
    - What if empty land is not present?
        -> return -1
    - What if there is no building in grid?
        -> not possible

Sol : 
=> BFS from all 0s : [TIME - O(N*M*no_of_0) SPACE - O(N*M)]
-> N : row in grid, M : col in grid
    - Only use this case when number of 0s <<< number of 1s
    - Considering every 0 as a eligible land, we'll calculate it's 
    distance from all buildings and sum it up, in end see which 0 has 
    least sum. 

=> BFS from all 1s : [TIME - O(N*M*no_of_1) SPACE - O(N*M)]
    - Only use this case when number of 1s <<< number of 0s
    - Perform BFS from all 1s present, and update grid array with dist
    for each bfs traversal for every 1 then in end find keep minimum 
    dist of a land. 

Similar Ques : 
    - Ref 296. Best Meeting Point
*/
class Solution {
public:
//BEST APPROACH
//BFS from all 1s
//TIME - O(N^2*M^2) SPACE - O(N*M)
    vector<int>dir_x = {1,-1,0,0};
    vector<int>dir_y = {0,0,1,-1};
    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return -1;
        int m = grid[0].size();

        // check if number of 1s >> number of 0s, if yes, then do BFS from 0s
        // int count0 = 0, count1 = 0, bfsSource = 1;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j] == 0) count0++;
        //         if(grid[i][j] == 1) count1++;
        //     }
        // } 

        // if(count0 < count1) bfsSource = 0;

        int totalBuilding = 0;
        vector<vector<int>>reach(n, vector<int>(m, 0));
        queue<pair<int, int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    totalBuilding++;
                    vector<vector<bool>>visited(n, vector<bool>(m, false));

                    q.push({i, j});
                    visited[i][j] = true;
                    int steps = -1;

                    while(!q.empty()){
                        int size = q.size();
                        while(size--){
                            auto curr = q.front(); q.pop();
                            int x = curr.first;
                            int y = curr.second;

                            for(int k=0;k<4;k++){
                                int x0 = x + dir_x[k];
                                int y0 = y + dir_y[k];

                                if(x0 >=0 && y0 >= 0 && x0 < n && y0 < m && 
                                grid[x0][y0] <= 0 && !visited[x0][y0]){
                                    grid[x0][y0] += steps;
                                    visited[x0][y0] = true;
                                    reach[x0][y0]++;
                                    q.push({x0, y0});
                                }
                            }
                        }
                        steps--;
                    }
                }
            }
        }

        int ans = INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] < 0 && reach[i][j] == totalBuilding) 
                    ans = max(ans, grid[i][j]);
            }
        }

        return ans == INT_MIN ? -1 : -ans;
    }
};