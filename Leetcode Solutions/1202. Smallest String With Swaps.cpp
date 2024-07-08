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
        void _union(int x, int y){
            int x_parent = find(x);
            int y_parent = find(y);

            if(x_parent == y_parent) return;

            if(rank[x_parent] >= rank[y_parent]){
                rank[x_parent] += rank[y_parent];
                parent[y_parent] = x_parent;
            }else{
                rank[y_parent] += rank[x_parent];
                parent[x_parent] = y_parent;
            }
        }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        UnionFind uf(n);
        
        for(int i=0;i<pairs.size();i++)
            uf._union(pairs[i][0], pairs[i][1]);
        
        unordered_map<int, pair<vector<char>,vector<int>>>root_to_child;
        
        for(int i=0;i<n;i++){
            int i_parent = uf.find(i);
            root_to_child[i_parent].first.push_back(s[i]);
            root_to_child[i_parent].second.push_back(i);
        }
        
        for(auto it : root_to_child){
            sort(it.second.first.begin(), it.second.first.end());
            
            for(int i=0;i<it.second.first.size();i++){
                char x = it.second.first[i];
                int index = it.second.second[i];
                
                s[index] = x;
            }
        }
        
        return s;
    }
};