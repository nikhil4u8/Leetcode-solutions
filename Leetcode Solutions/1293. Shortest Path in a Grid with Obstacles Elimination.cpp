class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int dir_x[4] = {0,0,1,-1};
        int dir_y[4] = {1,-1,0,0};
        
        //position(x,y), obstacles eliminated
        queue<vector<int>>q;
        q.push({0,0,k});
        
        unordered_map<string,pair<bool,int>>visited;
        int steps = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                vector<int>temp = q.front();
                q.pop();
                
                if(temp[0]<0 || temp[1]<0 || temp[0]>=m || temp[1]>=n) continue;
                
                string key = to_string(temp[0]) + ',' + to_string(temp[1]);        
                if(visited[key].first && visited[key].second >= temp[2]) continue;
                
                if(temp[0] == m-1 && temp[1] == n-1) return steps;        
                visited[key].first = true;
                visited[key].second = temp[2];
                
                for(int i=0;i<4;i++){
                    int x = temp[0] + dir_x[i];
                    int y = temp[1] + dir_y[i];
                    
                    if(x<m && y<n && x>=0 && y>=0){
                        if(grid[x][y] == 1 && temp[2] - 1 >= 0) q.push({x,y,temp[2]-1});
                        if(grid[x][y] == 0)  q.push({x,y,temp[2]});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};