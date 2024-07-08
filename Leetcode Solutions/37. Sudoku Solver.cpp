class Solution {
public:
    pair<int,int> next_empty_block(vector<vector<char>>&board,int x,int y){
        if(board[x][y] == '.') return {x,y};
        for(int i=y+1;i<9;i++){
            if(board[x][i] == '.') return {x,i};
        }
        
        for(int i=x+1;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') return {i,j};
            }
        }
        
        return {-1,-1};
    }
    bool issafe(vector<vector<char>>&board,int num,int x,int y){
        for(int i=0;i<9;i++){
            if(board[i][y]==num +'0' || board[x][i]==num+'0') return false;
        }
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i+3*(x/3)][j+3*(y/3)]==num+'0') return false;
            }
        }
        
        return true;
    }
    bool solve_sudoku(vector<vector<char>>&board,int x,int y){
        auto next = next_empty_block(board,x,y);
        
        if(next.first==-1 && next.second==-1) return true;
        
        for(int i=1;i<=9;i++){
            if(issafe(board,i,next.first,next.second)){
                board[next.first][next.second] = i+'0';
                if(solve_sudoku(board,next.first,next.second)) return true;
                board[next.first][next.second] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
         solve_sudoku(board,0,0);
    }
};