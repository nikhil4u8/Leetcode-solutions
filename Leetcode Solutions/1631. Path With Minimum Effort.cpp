// //Approach 1 - Backtracking, going through all the paths and finding minimum efforts path among them
// /*
// Approach 2 - Considering the grid as a graph, with the weight of each edge is absolute difference between heights, so we need to find min cost path from {0,0} as src to {n-1, m-1} as dest using Dijistra algo

// TIME - O(M*N*log(M*N)) -> log becoz we're using set to store edges in sorted manner
// SPACE - O(N*M)
// */
// class Solution {
// public:
//     int dir_x[4] = {0,0,1,-1};
//     int dir_y[4] = {1,-1,0,0};
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int n = heights.size();
//         if(n == 0) return 0;
//         int m = heights[0].size();
        
//         vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
//         vector<vector<int>>visited(n, vector<int>(m, false));
//         set<pair<int, pair<int,int>>>st;
        
//         dist[0][0] = 0;
//         st.insert({0, {0,0}});
        
//         while(!st.empty()){
//             auto top = st.begin();
            
//             int d = (top->first);
//             int x0 = (top->second.first);
//             int y0 = (top->second.second);
            
//             if(x0 == n-1 && y0 == m-1) return d;
            
//             st.erase(st.begin());
//             visited[x0][y0] = true;
            
//             for(int i=0;i<4;i++){
//                 int x = x0 + dir_x[i];
//                 int y = y0 + dir_y[i];
                
//                 if(x>=0 && y>=0 && x<n && y<m && !visited[x][y]){
//                     int curr_effort = abs(heights[x][y]-heights[x0][y0]);
//                     int max_effort_in_path = max(curr_effort, dist[x0][y0]);
                    
//                     if(dist[x][y] > max_effort_in_path){
//                         auto find = st.find({dist[x][y], {x,y}});
//                         dist[x][y] = max_effort_in_path;

//                         if(find != st.end()) st.erase(find);
//                         st.insert({dist[x][y], {x,y}});   
//                     }
//                 }
//             }
//         }
//         return dist[n-1][m-1];
//     }
// };
// /*
// Approach 3 - Binary Search Using BFS/DFS
// since our max efforts lies in range of 0-10^6, so we do a binary search in that range and for each mid point we can check if it's possible to reach dest with that height difference, it it's not then check for higher difference otherwise look for lower difference 

// TIME - O(log(1000000)*(M*N)) 
// SPACE - O(M*N)
// since for BFS time complexity is O(V+E) where V is vertices and E is edges, so in matrix -> vertices = M*N and edges = M*N, hence O(V+E) ~ O(M*N)
// */

class Solution {
public:
    int dir_x[4] = {0,0,1,-1};
    int dir_y[4] = {1,-1,0,0};
    bool checkPathExist(vector<vector<int>>&heights, int diff, int n, int m){
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        queue<pair<int,int>>q;
        
        q.push({0,0});
        visited[0][0] = true;
        
        while(!q.empty()){
            auto cordi = q.front(); q.pop();
            
            int x0 = cordi.first;
            int y0 = cordi.second;
            
            if(x0 == n-1 && y0 == m-1) return true;
            
            for(int i=0;i<4;i++){
                int x = x0 + dir_x[i];
                int y = y0 + dir_y[i];
                
                if(x>=0 && y>=0 && x<n && y<m && !visited[x][y]){
                    int curr_effort = abs(heights[x0][y0] - heights[x][y]);
                    
                    if(curr_effort <= diff){
                        visited[x][y] = true;
                        q.push({x,y});
                    }
                }
            }
        }
        
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        if(n == 0) return 0;
        int m = heights[0].size();
        
        int start = 0, end = 1000000;
        int ans = end;
        
        while(start<=end){
            int mid = (start+end)/2;
            if(checkPathExist(heights, mid, n, m)){
                ans = min(ans,mid);
                end = mid-1;
            }else start = mid+1;
        }
        
        return ans;
    }
};