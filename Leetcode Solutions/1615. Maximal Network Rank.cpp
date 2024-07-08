class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>indegree(n);
        unordered_map<int, unordered_map<int, int>>road;
        for(int i=0;i<roads.size();i++){
            indegree[roads[i][0]]++;
            indegree[roads[i][1]]++;
            
            road[roads[i][0]][roads[i][1]]++; 
            road[roads[i][1]][roads[i][0]]++;
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
                ans = max(ans, indegree[i]+indegree[j]-road[i][j]);
        }
        
        return ans;
    }
};