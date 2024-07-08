class Solution {
public:
    //Using DFS
    //Finding all possible path from src to target and finding minimum then
    int ans = INT_MAX;
    void DFS(int src, int dest, unordered_map<int, vector<int>>&mp, unordered_map<int, unordered_set<int>>&idx_stop, int stops, unordered_map<int, bool>&visited){
        if(src == dest){
            ans = min(ans, stops);
            return;
        }
        
        visited[src] = true;
        for(int i=0;i<mp[src].size();i++){
            int temp_stop = mp[src][i];
            
            if(idx_stop[temp_stop].find(dest) != idx_stop[temp_stop].end()){
                ans = min(ans, stops+1);
                return;
            }
            
            for(auto it : idx_stop[temp_stop]){
                if(!visited[it])
                    DFS(it, dest, mp, idx_stop, stops+1, visited);
            }
        }
        visited[src] = false;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //Bus stop -> vector of bus number
        unordered_map<int, vector<int>>mp;
        //bus number -> vector of bus stops
        unordered_map<int, unordered_set<int>>idx_stop;
        
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                mp[routes[i][j]].push_back(i);
                idx_stop[i].insert(routes[i][j]);
            }
        }
        
        unordered_map<int, bool>visited;
        DFS(source, target, mp, idx_stop, 0, visited);
        
        if(ans == INT_MAX) return -1;
        return ans;
    }
    //TIME - O(N*B) SPACE - O(N*B)
    //N is total number of buses
    //B is maximum number of stops for a bus
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        //Bus stop -> vector of bus number
        unordered_map<int, vector<int>>stop_idx;
        
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++)
                stop_num[routes[i][j]].push_back(i);
        }
        
        queue<int>q;
        unordered_map<int, bool>visited;
        
        //pushing all the stops which can be reached without changing bus
        for(int i=0;i<stop_num[source].size();i++){
            
            int bus_num = stop_num[source][i];
            if(visited[bus_num]) continue;
            visited[bus_num] = true;

            for(int j=0;j<routes[bus_num].size();j++){
                int stop = routes[bus_num][j];
                if(stop == target) return 1;
                q.push(stop);
            }
            
        }
        
        int step = 1;
        while(!q.empty()){
            int sz = q.size();
            step++;
            while(sz--){
                int stop = q.front();
                q.pop();
                
                //traversing to find which next bus should be taken to reach dest
                for(int i=0;i<stop_num[stop].size();i++){
                    
                    int next_bus_num = stop_num[stop][i];
                    if(!visited[next_bus_num]){
                        visited[next_bus_num] = true;
                        //travering all the stop for next_bus_num and pushing it into queue
                        for(int j=0;j<routes[next_bus_num].size();j++){
                            
                            int next_stop = routes[bus_num][j];
                            if(next_stop == target) return step;
                            q.push(next_stop);
                        
                        }
                    
                    }
                }
            }
        }
        
        return -1;
    }
};