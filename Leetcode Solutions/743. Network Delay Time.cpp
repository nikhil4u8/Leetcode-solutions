class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>>graph;
        for(int i=0;i<times.size();i++){
            graph[times[i][0]-1].push_back({times[i][1]-1, times[i][2]});
        }
        
        vector<bool>visited(n, false);
        vector<int>dist(n, INT_MAX);
        
        dist[k-1] = 0;
        int idx = k-1;
        int mini = INT_MAX;
        
        while(idx != -1){//cout<<idx<<" ";
            visited[idx] = true;
            
            for(int i=0;i<graph[idx].size();i++){
                int child = graph[idx][i].first;
                int weight = graph[idx][i].second;
                
                if(!visited[child] && dist[child] > dist[idx] + weight)
                    dist[child] = dist[idx] + weight;
            }
            
            mini = INT_MAX;
            idx = -1;
            for(int i=0;i<n;i++){cout<<dist[i]<<" ";
                if(!visited[i] && mini > dist[i]){
                    mini = dist[i];
                    idx = i;
                }
            }cout<<idx<<"\n";
        }
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
            ans = max(ans, dist[i]);
        
        if(ans == INT_MAX) return -1;
        return ans;
    }
};