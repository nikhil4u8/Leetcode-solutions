#define ppi pair<int, pair<int,int>>
class UnionFind{
    public:
        vector<int>parent;
        vector<int>rank;
        UnionFind(int size){
            parent = vector<int>(size, -1);
            rank = vector<int>(size, 1);
        }
        int find(int src){
            if(parent[src] == -1) return src;
            return find(parent[src]);
        }
        bool _union(int x, int y){
            int x_parent = find(x);
            int y_parent = find(y);
            
            if(x_parent == y_parent) return false;
            
            if(rank[x_parent] >= rank[y_parent]){
                rank[x_parent] += rank[y_parent];
                parent[y_parent] = x_parent; 
            }else{
                rank[y_parent] += rank[x_parent];
                parent[x_parent] = y_parent;
            }
            
            return true;
        }
};
class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        int m = wells.size();
        
        unordered_map<int, unordered_map<int,int>>graph;
        for(int i=0;i<pipes.size();i++)
            graph[pipes[i][0]][pipes[i][1]] = pipes[i][2];
        
        for(int i = 0;i<m;i++)
            graph[0][i+1] = wells[i];
        
        //Generate MST
        
        priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
        
        for(auto u : graph){
            int _u = u.first;
            for(auto v_weight : u.second){
                int _v = v_weight.first;
                int _weight = v_weight.second;
                
                pq.push({_weight, {_u, _v}});
            }
        }
        
        UnionFind uf(n+1);
        int mst_cost = 0;
        int edges_used = 0;
        
        while(!pq.empty()){
            auto temp = pq.top(); pq.pop();
            
            int weight = temp.first;
            int u = temp.second.first;
            int v = temp.second.second;
            
            if(uf._union(u, v)){
                mst_cost += weight;
                edges_used++;
            }
        }
        
        return mst_cost;
    }
};