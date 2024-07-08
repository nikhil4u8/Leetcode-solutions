class Solution {
public:
    int dir_x[4] = {1,-1,0,0};
    int dir_y[4] = {0,0,1,-1};
    bool DFS(vector<vector<char>>&board,vector<vector<bool>>&visited,int x,int y,int n,int m){
        bool res = true;
        visited[x][y] = true;
          
        for(int i=0;i<4;i++){
            int x0 = x + dir_x[i];
            int y0 = y + dir_y[i];
                
            if(x0>=0 && y0>=0 && x0<n && y0<m && !visited[x0][y0] && board[x0][y0]=='O')
                    res = res & DFS(board,visited,x0,y0,n,m);
        }
       
        if(x==0 || y==0 || x==n-1 || y==m-1) return false;
        
        return res;
    }
    void DFS2(vector<vector<char>>&board,int x,int y,int n,int m){
        board[x][y] = 'X';
        
        for(int i=0;i<4;i++){
            int x0 = x + dir_x[i];
            int y0 = y + dir_y[i];
                
            if(x0>=0 && y0>=0 && x0<n && y0<m && board[x0][y0]=='O')
                    DFS2(board,x0,y0,n,m);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !visited[i][j])
                    if(DFS(board,visited,i,j,n,m))
                        DFS2(board,i,j,n,m);
            }
        }
    }
};