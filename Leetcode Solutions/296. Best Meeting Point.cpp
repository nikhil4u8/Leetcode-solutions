/*
Ques to ask : 
    - What if grid contains all 0s or all 1s?
    - What if grid contains only 1 friend?
    - Does meeting point needs to be 0 or 1 or both?
    - How to find dist b/w 2 points?

Sol : 
=> Brute Force : BFS from all 0s : [TIME - O(N^2*M^2) SPACE - O(N*M)]
-> N : row in grid, M : col in grid
    - Only use this case when number of 0s <<< number of 1s
    - Considering every 0 as a eligible land, we'll calculate it's distance 
    from all buildings and sum it up, in end see which 0 has least sum. 

=> Brute Force : BFS from all 1s : [TIME - O(N^2*M^2) SPACE - O(N*M)]
    - Only use this case when number of 1s <<< number of 0s
    - Perform BFS from all 1s present, and update grid array with distance 
    for each bfs traversal for every 1 then in end find keep minimum distance 
    of a land. 

BEST APPROACH [Applied only when dist = manhatten dist]
=> Median : [TIME - O(NMlog(NM)) SPACE - O(NM)]
    - First, let's solve for 1D array, if we've array = [1,0,1] then 
    meeting_pt = 1st idx,
    now if array = [1,0,1,1] then meeting_pt = 2nd idx, meaning that best 
    meeting pt for 1D array doesn't depend on mean, it depends on weight 
    mean, wherever density of 1 will be more meeting point will be closer 
    to that area. Ex : array = [1,0,0,0,1,1,1], meeting_pt will lie near 
    last grp of "1s", so basically we've to find median of the 1D array 
    to find best meeting pt.
    - Now, for 2D array, we'll simply calculate the density of 1s in each 
    row / col, then using 1D approach we'll find the best meeting point 
    for row & col, so overall best meeting_pt = {best_meeting_row, 
    best_meeting_col}
        - Traverse whole matrix to find list of x / y cordinate where we've 
        a building, then individually sort them to find median in each list.
        - To find total walking dist, simply add abs(x_median - x) and 
        abs(y_median - y) to final ans.

NOTE : We'll find median when dist formula = manhatthen, if dist formula 
is sqrt one then find mean only.

Similar Ques : 
    - Ref 317. Shortest Distance from All Buildings
*/
class Solution {
public:
//BEST APPROACH : Median
//TIME - O(NMlog(NM)) SPACE - O(NM)
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();

        vector<int>row, col;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    row.push_back(j);
                    col.push_back(i);
                }
            }
        }

        sort(row.begin(), row.end());
        sort(col.begin(), col.end());

        int rSize = row.size();
        int cSize = col.size();

        int xMedian = row[rSize / 2];
        int yMedian = col[cSize / 2];

        int ans = 0;
        for(auto it : row) ans += abs(xMedian - it);
        for(auto it : col) ans += abs(yMedian - it);

        return ans;
    }
//APPROACH 1 : BRUTE FORCE
//TIME - [TIME - O(N^2*M^2) SPACE - O(N*M)]
    vector<int>dir_x = {0,0,1,-1};
    vector<int>dir_y = {1,-1,0,0};
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;

        int m = grid[0].size();

        int count_1 = 0, count_0 = 0, src = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) count_1++;
                else count_0++;
            }
        }

        if(count_1 >= count_0) src = 0;
        if(count_1 == n*m) src = 1;

        vector<vector<int>>distSum(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == src){
                    queue<pair<int, int>>q;
                    vector<vector<bool>>visited(n, vector<bool>(m, false));

                    q.push({i, j});
                    visited[i][j] = true;
                    int steps = 1;

                    while(!q.empty()){
                        int size = q.size();
                        while(size--){
                            auto curr = q.front(); q.pop();
                            int x = curr.first;
                            int y = curr.second;

                            for(int k=0;k<4;k++){
                                int x0 = x + dir_x[k];
                                int y0 = y + dir_y[k];

                                if(x0 >= 0 && y0 >= 0 && x0 < n && y0 < m &&
                                !visited[x0][y0]){
                                    distSum[x0][y0] += steps;
                                    visited[x0][y0] = true;
                                    q.push({x0, y0});
                                }
                            }
                        }
                        steps++;
                    }
                }
            }
        }

        int minDistSum = INT_MAX;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                minDistSum = min(minDistSum, distSum[i][j]);
            }
        }

        return minDistSum == INT_MAX ? -1 : minDistSum;
    }
};