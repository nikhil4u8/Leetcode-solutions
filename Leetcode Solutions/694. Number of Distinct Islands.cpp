class Solution {
public:
    //Time - O(MNlogn(MN)) as hashing was not possible
    //Space - O(MN) for the islands array and final set
    vector<vector<pair<int,int>>>islands;
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int m,n;
    void bfs(int r,int c,vector<vector<int>>& grid, vector<vector<bool>>&visited){   
        vector<pair<int,int>>island;
        visited[r][c]=true;
        
        queue<pair<int,int>>q;
        q.push({r,c});
        
        while(!q.empty()){
            pair<int,int>front=q.front();
            q.pop();
            island.push_back({front.first,front.second});
            for(auto d:dir)
            {
                int x=front.first+d[0],y=front.second+d[1];
                if(x>=0 and x<m and y>=0 and y<n and grid[x][y]==1 and !visited[x][y])
                {
                    q.push({x,y});
                    visited[x][y]=true;
                }
            }
        }
        islands.push_back(island);
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 and !visited[i][j])
                    bfs(i,j,grid,visited);
            }
        }
        
        set<vector<pair<int,int>>>s;
        for(int i=0;i<islands.size();i++){
            for(int j=1;j<islands[i].size();j++)    {
                islands[i][j].first-=islands[i][0].first;
                islands[i][j].second-=islands[i][0].second;
            }
            islands[i][0].first=0,islands[i][0].second=0;
            s.insert(islands[i]);
        }
        
        return s.size();      
    }
};
class Solution {
public:
    //Key is to generate a hash for each shape
    //To describe the shape,is to describe its moving directions assuming we start at the first 1 we meet s - start, and move 0-down,1-up,2-right,3-left.
    
    //TIME - O(M*N) SPACE - O(M*N)
    vector<vector<vector<pair<int,int>>>>temp;
    int dir_x[4] = {1,-1,0,0};
    int dir_y[4] = {0,0,1,-1};
    int count = 0;
    
    void DFS(vector<vector<int>>&grid,int x,int y,vector<vector<bool>>&visited,int n,int m,string &str){
        visited[x][y] = true;
    
        for(int i=0;i<4;i++){
            int x0 = x + dir_x[i];
            int y0 = y + dir_y[i];
            
            if(x0>=0 && y0>=0 && x0<n && y0<m && !visited[x0][y0] && grid[x0][y0] == 1){
                //Another way to hash shape
                //str += "(" + to_string(x-x0) + "," + to_string(y-y0) + ")";
                str += to_string(i);
                DFS(grid,x0,y0,visited,n,m,str);
                str += "_";
            }
        }
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        set<string>distinct_set_of_island;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    string pattern = "";
                    //not necessary
                    pattern += "s";
                    DFS(grid,i,j,visited,n,m,pattern);
                    distinct_set_of_island.insert(pattern);   
                }
            }
        }
        
        return distinct_set_of_island.size();
    }
    **To improve space complexity instead of visited array mark visited element in grid as 0
};
