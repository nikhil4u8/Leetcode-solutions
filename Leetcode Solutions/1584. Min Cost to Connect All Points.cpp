//PRIM'S ALGO
class Solution {
public:
    //TIME - O(N^2 * logN) SPACE - O(N^2)
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0, edgeUsed = 0;
    
        vector<bool>visited(n, false);
        vector<int>min_dist(n, INT_MAX);
        
        min_dist[0] = 0;
        //only n-1 edge should be used
        while(edgeUsed < n){
            int mini = INT_MAX, idx = 0;
            
            for(int i=0;i<n;i++){
                if(!visited[i] && mini > min_dist[i]){
                    mini = min_dist[i];
                    idx = i;
                }
            }
            
            visited[idx] = true;
            ans += mini;
            edgeUsed++;
            
            //pushing weight of all the edges from point[node]
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    int next_weight = abs(points[i][0] - points[idx][0]) + 
                                      abs(points[i][1] - points[idx][1]);
                    
                    min_dist[i] = min(min_dist[i], next_weight);
                }
            }
        }
        
        return ans;
    }
};