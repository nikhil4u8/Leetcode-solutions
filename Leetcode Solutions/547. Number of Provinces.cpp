class Solution {
public:
    int find(vector<int>&parent, int src){
        if(parent[src] == -1) return src;
        return find(parent, parent[src]);
    }
    void _union(int x, int y, vector<int>&parent){
        int x_parent = find(parent, x);
        int y_parent = find(parent, y);
        
        if(x_parent == y_parent) return;
        
        parent[x_parent] = y_parent;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>parent(n, -1);
        
        for(int i=0;i<n;i++){
            int u = i;
            for(int j=0;j<n;j++){
                int v = j;
                if(isConnected[i][j])
                    _union(u, v, parent);
            }
        }
        
        int count = 0;
        for(int i=0;i<n;i++){
            if(parent[i] == -1) count++;    
        }
        
        return count;
    }
};