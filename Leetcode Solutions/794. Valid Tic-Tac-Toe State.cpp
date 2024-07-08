class Solution {
public:
    //TIME - O(1) SPACE - O(1)
    bool isWin(vector<string>&board, char c)
    {
        for(int i = 0; i < 3; i++){
            if(board[i][0] == c && board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return true;
            else if(board[0][i] == c && board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return true;
        }
        if(board[0][0] == c && board[1][1] == board[0][0] && board[2][2] == board[0][0])
            return true;
        else if(board[0][2] == c && board[1][1] == board[0][2] && board[2][0] == board[0][2])
            return true;
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        int count_o=0,count_x=0;
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]=='O') count_o++;
                if(board[i][j]=='X') count_x++;
                if(board[i][j]==' ') board[i][j]='#';
            }
        }
        
        
        bool win_flag_o=isWin(board,'O'),win_flag_x=isWin(board,'X');
        
        if(count_x==count_o) return !win_flag_x;
        if(count_o+1 == count_x) return !win_flag_o;
       
        return false;
    }
};