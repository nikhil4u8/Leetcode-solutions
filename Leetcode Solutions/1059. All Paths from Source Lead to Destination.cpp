class Solution {
public:
    bool solve(unordered_map<int, vector<int>>&graph, int src, int dest, vector<bool>visited){
        if(src == dest) return graph[dest].size() == 0;
        if(src != dest && graph[src].size() == 0) return false;
        
        visited[src] = true;
        
        for(int i=0;i<graph[src].size();i++){
            int child = graph[src][i];
            if(!visited[child] && solve(graph, child, dest, visited)) continue;
            else return false;
        }
        
        return true;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>>graph;
        for(int i=0;i<edges.size();i++)
            graph[edges[i][0]].push_back(edges[i][1]);
        
        vector<bool>visited(n, false);
        return solve(graph, source, destination, visited);
    }
};