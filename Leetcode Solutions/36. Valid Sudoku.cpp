class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //checking each row
        for(int i=0;i<9;i++){
            vector<bool>row(10, false);
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '0';
                if(row[num]) return false;
                row[num] = true;
            }
        }

        //checking each col
        for(int j=0;j<9;j++){
            vector<bool>col(10, false);
            for(int i=0;i<9;i++){
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '0';
                if(col[num]) return false;
                col[num] = true;
            }
        }

        //checking each square
        for(int i=0;i<3;i++){
            int t = 0;
            while(t < 3){
                vector<bool>square(10, false);
                for(int j=3*i;j<3*(i+1);j++){
                    for(int k=3*t;k<3*(t+1);k++){
                        if(board[k][j] == '.') continue;

                        int num = board[k][j] - '0';
                        if(square[num]) return false;
                        square[num] = true;
                    }
                }
                t++;
            }
        }

        return true;
    }
};