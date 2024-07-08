#define ppi pair<int,pair<int,int>>
class Solution {
public:
    //Dijistra
    /*
    Here we didn't maintained dist and visited array, 
    dist array - as there are routes whose len is shorter but pass more stops hence not included in answer. So the sol is to put all the possible route into heap so that all of them has a chance to processed. And sol simply returns the first qualified route
    
    visited array - we needed visited map so that it wont go into infinite loop. here "k" limited the time we can visit a single node that it wont go into an infinite loop.
    */
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         unordered_map<int, unordered_map<int,int>>graph;
        
//         for(int i=0;i<flights.size();i++)
//             graph[flights[i][0]][flights[i][1]] = flights[i][2];
        
//         priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
//         pq.push({0, {src, k+1}});
        
//         while(!pq.empty()){
//             auto curr = pq.top(); pq.pop();

//             int dist = curr.first;
//             int u = curr.second.first;
//             int stops = curr.second.second;
            
//             if(u == dst) return dist;
//             if(stops <= 0) continue;
            
//             for(auto it : graph[u]){
//                 int v = it.first;
//                 int wt = it.second;
//                 pq.push({dist + wt, {v, stops-1}});
//             }
//         }
        
//         return -1;
//     }
    //DFS
    //TIME - O(V*K) SPACE - O(V)
    //V -> len of flights
//     int ans = INT_MAX;
//     void solve(int src, int dest, int cost, int stop, 
//               unordered_map<int, unordered_map<int,int>>&graph, vector<bool>visited){
//         if(src == dest){
//             if(stop >= 0) ans = min(ans, cost);
//             return;
//         }
        
//         visited[src] = true;
//         for(auto it : graph[src]){
//             int v = it.first;
//             int wt = it.second;
            
//             if(visited[v]) continue;
//             solve(v, dest, cost + wt, stop - 1, graph, visited);
//         }
//     }
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         unordered_map<int, unordered_map<int,int>>graph;
//         vector<bool>visited(n, false);
        
//         for(int i=0;i<flights.size();i++)
//             graph[flights[i][0]][flights[i][1]] = flights[i][2];
        
//         solve(src, dst, 0, k+1, graph, visited);
        
//         if(ans == INT_MAX) return -1;
//         return ans;
//     }
    //BELLMAN FORD
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k+2, vector<int>(n, INT_MAX));
        //dp[i][j] = Dist to reach j using atmost i edges from src
        for(int i = 0; i<=k+1; i++)
            dp[i][src] = 0; // Dist to reach src always zero
        
        //dp[i][j] = min(dist[i-1][u] + flight[u][j])
        for(int i=1;i<=k+1;i++){
            for(int j=0;j<flights.size();j++){
                //Using indegree
                int u = flights[j][0];
                int v = flights[j][1];
                int wt = flights[j][2];
                
                if(dp[i-1][u] != INT_MAX)
                    dp[i][v] = min(dp[i][v], dp[i-1][u] + wt);
            }
        }
        
        return dp[k+1][dst] == INT_MAX ? -1: dp[k+1][dst];
    }
};
