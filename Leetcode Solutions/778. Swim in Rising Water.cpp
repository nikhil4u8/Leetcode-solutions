// //Approach 1 - Heap
// //Approach 2 - MST or using UNION-FIND
// //Approach 3 - DFS + Binary Search
// //Approach 4 - DP
#define ppi pair<int, pair<int,int>>
class Solution {
public:
    int dir_x[4] = {0,0,1,-1};
    int dir_y[4] = {1,-1,0,0};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<bool>visited(n*n, false);
        priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
        
        pq.push({grid[0][0], {0,0}});
        visited[grid[0][0]] = true;
        
        int ans = 0;
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            
            ans = max(ans, curr.first);
            int x0 = curr.second.first;
            int y0 = curr.second.second;
            
            if(x0 == n-1 && y0 == n-1) return ans;
            
            for(int i=0;i<4;i++){
                int x = x0 + dir_x[i];
                int y = y0 + dir_y[i];
                
                if(x>=0 && y>=0 && x<n && y<n && !visited[grid[x][y]]){
                    visited[grid[x][y]] = true;
                    pq.push({grid[x][y], {x,y}});
                }
            }
        }
        
        return ans;
    }
};
// --> DFS + Binary Search
// class Solution {
// public:
//     //TIME - O(N^2 * log(N^2)) SPACE - O(N^2)
//     int dir_x[4] = {0,0,1,-1};
//     int dir_y[4] = {1,-1,0,0};
//     bool checkPathExist(vector<vector<int>>&grid, int path_threshold, int n){
//         vector<vector<bool>>visited(n, vector<bool>(n, false));
//         queue<pair<int,int>>q;
        
//         if(grid[0][0] > path_threshold) return false;
//         q.push({0,0});
//         visited[0][0] = true;
        
//         while(!q.empty()){
//             int size = q.size();
//             while(size--){
//                 auto curr = q.front(); q.pop();
                
//                 int x0 = curr.first;
//                 int y0 = curr.second;
//                 if(x0 == n-1 && y0 == n-1) return true;
                
//                 for(int i=0;i<4;i++){
//                     int x = x0 + dir_x[i];
//                     int y = y0 + dir_y[i];
                    
//                     if(x>=0 && y>=0 && x<n && y<n && !visited[x][y]){
//                         int curr_threshold = grid[x][y];
//                         if(curr_threshold <= path_threshold){
//                             q.push({x,y});
//                             visited[x][y] = true;
//                             if(x == n-1 && y == n-1) return true;
//                         }
//                     }
//                 }
//             }
//         }
        
//         return false;
//     }
//     int swimInWater(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int max_time = n*n, ans = INT_MAX;
        
//         int i = 0, j = max_time-1;
//         while(i<=j){
//             int mid = (j+i)/2;
//             if(checkPathExist(grid, mid, n)){
//                 ans = min(ans, mid);
//                 j = mid-1;
//             }else i = mid + 1;
//         }
        
//         return ans;
//     }
// };

// --> DP
// class Solution {
// public:
//     int dir_x[4] = {0,0,1,-1};
//     int dir_y[4] = {1,-1,0,0};
//     vector<vector<int>>dp = vector<vector<int>>(51, vector<int>(51, INT_MAX));
//     void DFS(vector<vector<int>>& grid,int x,int y,int curr, int n){
//         int maxi = max(curr, grid[x][y]);
//         if(maxi >= dp[x][y]) return;    
//         cout<<x<<" "<<y<<" "<<maxi<<"\n";
//         dp[x][y] = maxi;
        
//         for(int i=0;i<4;i++){
//             int x0 = x + dir_x[i];
//             int y0 = y + dir_y[i];
            
//             if(x0>=0 && y0>=0 && x0<n && y0<n)
//                 DFS(grid, x0, y0, dp[x][y], n);
//         }
//     }
//     int swimInWater(vector<vector<int>>& grid) {
//         int n=grid.size();
//         DFS(grid, 0, 0, grid[0][0], n);
        
//         return dp[n-1][n-1];
//     }
// };
