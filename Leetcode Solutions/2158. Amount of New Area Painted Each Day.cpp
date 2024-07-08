//Approach 1 - Using Set insert all points in set and remove them one by one after painting it
//Approach 2 - Using Union Find
//Approach 3 - Merge Intervals -> For each interval
class UnionFind {
    public:
         vector<int>parent, rank, _max;
         UnionFind(int N) {
            parent = vector<int>(N, -1);
            rank = vector<int>(N, 1);
            _max = vector<int>(N, 0);
             
            for (int i = 0; i < N; i++)
                _max[i] = i;
        }
        int find(int src) {
            if(parent[src] == -1) return src;
            return find(parent[src]);
        }
        void _union(int x, int y) {
            int x_parent = find(x);
            int y_parent = find(y);
            
            if(x_parent == y_parent) return;
            
            if(rank[x_parent] >= rank[y_parent]){
                rank[x_parent] += rank[y_parent];
                parent[y_parent] = x;
                _max[x_parent] = max(_max[x_parent], _max[y_parent]);
            }else{
                rank[y_parent] += rank[x_parent];
                parent[x_parent] = y;
                _max[y_parent] = max(_max[x_parent], _max[y_parent]);
            }
        }
         int maxi(int p) {
            return _max[find(p)];
        }
    };  
class Solution {
public:
    //Inserting all points from mini to maxi into set and taking out avaiable points between start and end and deleting those from set.
    //TIME - O(NlogN) -> N is maxi-mini
    //SPACE - O(N)
//     vector<int> amountPainted(vector<vector<int>>& paint) {
//         int mini = INT_MAX, maxi = INT_MIN;
//         for(int i=0;i<paint.size();i++){
//             mini = min(mini, paint[i][0]);
//             maxi = max(maxi, paint[i][1]);
//         }
        
//         set<int>painting;
//         for(int i=mini;i<=maxi;i++)
//             painting.insert(i);
        
//         vector<int>ans;
//         for(int i=0;i<paint.size();i++){
//             int start = paint[i][0];
//             int end = paint[i][1];
            
//             int res = 0;
            
//             auto it = lower_bound(painting.begin(), painting.end(), start);
//             while(it != painting.end() && *it < end){
//                 res++;
//                 it = painting.erase(it);
//             }
            
//             ans.push_back(res);
//         }
        
//         return ans;
//     }
    
    //TIME - O(N) SPACE - O(N) 
    //N is total amount of area which needs to be painted
    //In each index of parent array we store the parent of current index and in _maxi arrau we store maximum index at which the current interval is ending and we traverse through paint array and we merge start, start+1, and then we make start point to next availabke point using union-find
//     vector<int> amountPainted(vector<vector<int>>& paint) {
//         UnionFind uf(50001);
        
//         vector<int>result(paint.size(), 0);
        
//         for (int i = 0; i < paint.size(); i++) {
//             int amount = 0;
//             int start = uf.maxi(paint[i][0]), end = paint[i][1];
            
//             while (start < end) {
//                 uf._union(start, start + 1);
//                 amount++;
//                 start = uf.maxi(start);
//             }
            
//             result[i] = amount;
//         }
        
//         return result;
//     }
    vector<vector<int>> list;
    vector<int> amountPainted(vector<vector<int>>&paint) {
        int n = paint.size();
        vector<int> res(n, 0);
        
        for(int i=0; i<n; i++)
            res[i] = addInterval(paint[i]);
        
        return res;
    }
    int addInterval(vector<int>cur) {
        vector<vector<int>>merge;
        
        int i = 0, res = cur[1] - cur[0];
        
        while(i<list.size() && list[i][1] < cur[0])
            merge.push_back(list[i++]);
        
        while(i<list.size() && list[i][0] <= cur[1]) {
            int save = min(cur[1], list[i][1]) - max(cur[0], list[i][0]);
            res -= max(save, 0);
            cur[0] = min(list[i][0], cur[0]);
            cur[1] = max(list[i][1], cur[1]);
            i++;
        }
        merge.push_back(cur);
        while(i<list.size()) {
            merge.push_back(list[i++]);
        }
        
        list = merge;
        
        return res;
    }
};