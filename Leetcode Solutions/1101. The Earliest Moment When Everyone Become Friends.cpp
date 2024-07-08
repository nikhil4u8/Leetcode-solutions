class Solution {
public:
    int total_parent;
    int find(vector<int>&parent, int src){
        if(parent[src] == -1) return src;
        return find(parent, parent[src]);
    }
    void _union(int x, int y, vector<int>&parent){
        int x_parent = find(parent, x);
        int y_parent = find(parent, y);
        
        if(x_parent == y_parent) return;
        
        parent[x_parent] = y_parent;
        total_parent--;
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        vector<int>parent(n, -1);
        total_parent = n;
        
        for(int i=0;i<logs.size();i++){
            _union(logs[i][1], logs[i][2], parent);
            if(total_parent == 1) return logs[i][0];
        }
        
        return -1;
    }
};