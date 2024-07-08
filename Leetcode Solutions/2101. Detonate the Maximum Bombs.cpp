class Solution {
public:
    int dist(int x, int y, int x0, int y0, int r){
        long long int sum = (long long int)(x-x0)*(x-x0) + (long long int)(y-y0)*(y-y0);
        return sum <= (long long int)r*r;
    }
    void DFS(int src, vector<bool>&visited, vector<vector<int>>& bomb, int &count){
        visited[src] = true;
        count++;
        
        int x = bomb[src][0];
        int y = bomb[src][1];
        int r = bomb[src][2];
        
        for(int i=0;i<bomb.size();i++){
            if(!visited[i]){
                int x0 = bomb[i][0];
                int y0 = bomb[i][1];
                
                if(dist(x, y, x0, y0, r))
                    DFS(i, visited, bomb, count);
            }
        }
        
        //return ans;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = 0;
        int n = bombs.size();
        unordered_map<int, unordered_map<int,int>>bomb;
        
        for(int i=0;i<n;i++) bomb[bombs[i][0]][bombs[i][1]] = i;
        
        for(int i=0;i<n;i++){
            vector<bool>visited(n, false);
            int count = 0;
            DFS(i, visited, bombs, count);cout<<count<<" ";
            ans = max(ans, count);
        }
        
        return ans;
    }
};