class Solution {
public:
    //DFS
    bool reach(int src, int dest, unordered_map<int, vector<int>>&graph, vector<bool>&visited){
        if(src == dest) return true;
        if(visited[src]) return false;
        
        visited[src] = true;
        for(int i=0;i<graph[src].size();i++){
            int child = graph[src][i];
            if(!visited[child] && reach(child, dest, graph, visited))
                return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>>graph;
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool>visited(n, false);
        return reach(source, destination, graph, visited);
    }
    
    //UNION - FIND
//     int find(vector<int>&parent, int src){
//         if(parent[src] == -1) return src;
//         return find(parent, parent[src]);
//     }
//     void _union(int x, int y, vector<int>&parent){
//         int x_parent = find(parent, x);
//         int y_parent = find(parent, y);
        
//         if(x_parent == y_parent) return;
//         parent[x_parent] = y_parent;
//     }
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         vector<int>parent(n, -1);
//         for(int i=0;i<edges.size();i++){
//             _union(edges[i][0], edges[i][1], parent);
//         }
        
//         int src_parent = find(parent, source);
//         int dest_parent = find(parent, destination);
//         return src_parent == dest_parent;
//     }
};