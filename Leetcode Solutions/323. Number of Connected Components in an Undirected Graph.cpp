class Solution {
public:
    //UNION FIND
    //TIME - O(E+V) SPACE - O(V)
    int find_parent(vector<int>parent, int src){
        if(parent[src] == -1) return src;
        return find_parent(parent, parent[src]);
    }
    void _union(vector<int>&parent, vector<int>&size, int x, int y, int &total_parent){
        int x_parent = find_parent(parent, x);
        int y_parent = find_parent(parent, y);
        
        if(x_parent == y_parent) return;
        
        total_parent--;
        if(size[x_parent] > size[y_parent]){ 
            parent[y_parent] = x_parent; 
            size[x_parent] += size[y_parent];
        }else{ 
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>size(n, 1);
        vector<int>parent(n, -1);
        
        int component = n;
        
        for(int i=0;i<edges.size();i++)
            _union(parent, size, edges[i][0], edges[i][1], component);
    
        return component;
    }
    //NORMAL DFS
    //TIME - O(E+V) SPACE - O(E+V)
//     void DFS(unordered_map<int, vector<int>>&graph, int src, vector<bool>&visited){
//         visited[src] = true;
        
//         for(int i=0;i<graph[src].size();i++){
//             int child_node = graph[src][i];
//             if(!visited[child_node])
//                 DFS(graph, child_node, visited);
//         }
//     }
//     int countComponents(int n, vector<vector<int>>& edges) {
//         unordered_map<int, vector<int>>graph;
//         //Time - O(E)
//         for(int i=0;i<edges.size();i++){
//             graph[edges[i][0]].push_back(edges[i][1]);
//             graph[edges[i][1]].push_back(edges[i][0]);
//         }
        
//         int component = 0;
//         vector<bool>visited(n, false);
        
//         //TIME - O(V), since each.vertex is traversed once
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//                 DFS(graph, i, visited);
//                 component++;
//             }
//         }
        
//         return component;
//     }
};