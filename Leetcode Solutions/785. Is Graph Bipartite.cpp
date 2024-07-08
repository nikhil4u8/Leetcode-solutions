class Solution {
public:
    //TIME - O()
    bool DFS(int src, vector<vector<int>>&graph, vector<int>&color, int c){
        if(color[src] != -1 && color[src] == c) return false;
        
        for(int i=0;i<graph[src].size();i++){
            int v = graph[src][i];
            
            if(color[v] != -1 && color[v] != c) return false;
            else if(color[v] == -1){
                color[v] = c;
                if(!DFS(v, graph, color, abs(c-1))) return -1;
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int>color(n, -1);
        int c = 1;        

        //inserting all 
        for(int i=0;i<n;i++){
            int temp_c = c;
            if(color[i] != -1) temp_c = color[i];

            color[i] = temp_c;
            if(!DFS(i, graph, color, abs(temp_c - 1))) return false;
        }
    
        return true;
    }
};