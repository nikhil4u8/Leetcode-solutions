//A graph is a tree if :- 
//1. No cycle
//2. one Strongly connected component
class Solution {
public:
    bool isCyclic(unordered_map<int, vector<int>>&graph, vector<int>&indegree, int total_node){
        queue<int>q;
        for(int i=0;i<indegree.size();i++)
            if(indegree[i] == 1) q.push(i);
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            
            for(int i=0;i<graph[node].size();i++){
                int child = graph[node][i];
                indegree[child]--;
                if(indegree[child] == 1)
                    q.push(child);
            }
        }
        
        for(int i=0;i<total_node;i++){
            if(indegree[i] > 1) return true;
        }
            
        return false;
    }
    void isSCC(unordered_map<int, vector<int>>&graph, vector<bool>&visited, int src){
        visited[src] = true;
        
        for(int i=0;i<graph[src].size();i++){
            int child = graph[src][i];
            if(!visited[child])
                isSCC(graph, visited, child);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>graph;
        vector<int>indegree(n, 0);
        
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }
        
        if(isCyclic(graph, indegree, n)) return false;
        
        vector<bool>visited(n, false);
        isSCC(graph, visited, 0);
        
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        
        return true;
    }
};