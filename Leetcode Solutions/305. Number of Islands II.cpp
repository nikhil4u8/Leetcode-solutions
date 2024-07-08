//UNION-FIND
//Considering every point as a parent first, so if converted to land 
//then merge it with all the 4 direction points, and count total parent 
//left
class Solution {
public:
    int island = 0;
    int dir_x[4] = {0,0,1,-1};
    int dir_y[4] = {1,-1,0,0};
    pair<int,int> find(vector<vector<pair<int,int>>>&parent, int x, int y){
        if(parent[x][y] == make_pair(-1,-1)) return {x,y};
        return find(parent, parent[x][y].first, parent[x][y].second);
    }
    void _union(int x1, int y1, int x2, int y2, vector<vector<pair<int,int>>>&parent){
        pair<int,int> parent_1 = find(parent, x1, y1);
        pair<int,int> parent_2 = find(parent, x2, y2);
        
        if(parent_1 == parent_2) return;
        
        island--;
        parent[parent_1.first][parent_1.second] = parent_2;
    }
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<vector<pair<int,int>>>parent(m, vector<pair<int,int>>(n, make_pair(-2,-2)));
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        
        vector<int>ans;
        
        for(int i=0;i<positions.size();i++){
            int x0 = positions[i][0];
            int y0 = positions[i][1];
            
            if(parent[x0][y0] != make_pair(-2,-2)){
                ans.push_back(island);
                continue;
            }
            
            parent[x0][y0] = {-1,-1};
            island++;
            
            for(int j=0;j<4;j++){
                int x = x0 + dir_x[j];
                int y = y0 + dir_y[j];
               
                if(x>=0 && y>=0 && x<m && y<n && parent[x][y] != make_pair(-2,-2))
                    _union(x0, y0, x, y, parent);
            }
            
            ans.push_back(island);
        }
        
        return ans;
    }
};