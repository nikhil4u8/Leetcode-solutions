class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>ans(n, -1);
        ans[0] = 0;

        unordered_map<int, vector<pair<int, int>>>graph;
        for(int i=0;i<redEdges.size();i++)
            graph[redEdges[i][0]].push_back({redEdges[i][1], 1});

        for(int i=0;i<blueEdges.size();i++)
            graph[blueEdges[i][0]].push_back({blueEdges[i][1], -1});

        int steps = 1;
        //each node can have only 2 color edges linked to it, hence using unordered map
        //could have used vector<vector<>> too
        vector<unordered_map<int, bool>>visited(n);        
        queue<pair<int, int>>q;
        
        visited[0][1] = true;
        visited[0][-1] = true;

        for(int i=0;i<graph[0].size();i++){ 
            int node = graph[0][i].first;
            int color = graph[0][i].second;

            //to avoid adding self edge of same color again and again
            if(visited[node][color]) continue;
            
            //adding all adjacent edge to 0, along with their color to help find next color
            visited[node][color] = true;
            ans[node] = steps;
            q.push({node, color});
        }

        while(!q.empty()){
            int size = q.size();
            steps++;

            while(size--){
                auto curr = q.front(); q.pop();
                int color = curr.second;

                //iterating in adjacent edges of curr node
                for(int i=0;i<graph[curr.first].size();i++){
                    int node = graph[curr.first][i].first;
                    int temp_color = graph[curr.first][i].second;

                    //if next edge is not visited and temp_color is opposite of color
                    //then mark the edge visited, and push the node in queue
                    if(!visited[node][temp_color] && 
                    temp_color + color == 0){

                        visited[node][temp_color] = true;
                        if(ans[node] == -1) ans[node] = steps;
                        else ans[node] = min(steps, ans[node]);
                        q.push({node, temp_color});

                    }
                }
            }
        }

        return ans;
    }
};