class Solution {
public:
    int find_parent(vector<int>&parent, int src){
        if(parent[src] == -1) return src;
        return find_parent(parent, parent[src]);
    }
    int _union(vector<int>&parent, vector<int>&size, int x, int y){
        int x_parent = find_parent(parent, x);
        int y_parent = find_parent(parent, y);
        
        if(x_parent == y_parent) return 0;
        
        if(size[x_parent] > size[y_parent]){
            size[x_parent] += size[y_parent];
            parent[y_parent] = x_parent;
        }else{
            size[y_parent] += size[x_parent];
            parent[x_parent] = y_parent;
        }
        
        return 1;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n, -1);
        vector<int>size(n, 1);
        
        int last_index = 0;
        for(int i=0;i<n;i++){
            if(_union(parent, size, edges[i][0]-1, edges[i][1]-1) == 0) 
                last_index = i;
        }
        
        return edges[last_index];
    }
};