//5:58
#define ppi pair<int,int>
class Solution {
public:
    
    //Selecting top 3 hightest score node from each node and then calculating maximum score
    //https://leetcode.com/problems/maximum-score-of-a-node-sequence/discuss/1953669/Python-Explanation-with-pictures-top-3-neighbors.
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        const int n = scores.size();
        vector<vector<int>> adj(n);
        for (const vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for (vector<int>& a : adj) {
            // priority queue for top scored 3 vertices:
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            for (int v : a) {
                int score = scores[v];
                if (pq.size() < 3 || pq.top().first < score) {
                    pq.push({score, v});
                    if (pq.size() > 3) {
                        pq.pop();
                    }
                }
            }
            a.resize(pq.size());
            for (int i = a.size() - 1; i >= 0; --i) {
                a[i] = pq.top().second;
                pq.pop();
            }
        }
        
        int result = -1;
        for (const vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int base = scores[u] + scores[v];
            for (int x : adj[u]) {
                if (x == v) continue; // intersection - not allowed, continue
                
                for (int y : adj[v]) {
                    if (y == u || x == y) continue; // intersection - not allowed, continue
                    
                    result = max(result, base + scores[x] + scores[y]);
                }
            }
        }
        
        return result;
    }
    //BRUTE FORCE - TLE
//     int DFS(unordered_map<int, vector<int>>&graph, vector<bool>visited, 
//             int src, vector<int>scores, int left_node){
//         if(left_node == 0) return 0;
//         if(left_node == 1) return scores[src];
        
//         visited[src] = true;
//         int ans = -1;
        
//         for(int i=0;i<graph[src].size();i++){
//             int child = graph[src][i];
            
//             if(!visited[child]){
//                 int temp_score = DFS(graph, visited, child, scores, left_node-1);
//                 if(temp_score != -1) ans = max(ans, scores[src] + temp_score);
//             }
//         }

//         return ans;
//     }
//     int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
//         int n = scores.size();
        
//         unordered_map<int, vector<int>>graph;
//         for(int i=0;i<edges.size();i++){
//             graph[edges[i][0]].push_back(edges[i][1]);
//             graph[edges[i][1]].push_back(edges[i][0]);
//         }
        
//         int ans = -1;
        
//         vector<bool>visited(n, false);
//         for(int i=0;i<n;i++){
//             ans = max(ans, DFS(graph, visited, i, scores, 4));
//         }
        
//         return ans;
//     }
};