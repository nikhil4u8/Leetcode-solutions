//TIME - O(8*N*M) SPACE - O(1)
class Solution {
public:
    int dirx[8] = {0,0,1,-1,1,1,-1,-1};
    int diry[8] = {1,-1,0,0,1,-1,1,-1};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>click) {
        int n = board.size();
        int m = board[0].size();
        
        int x = click[0], y = click[1];
        
        //if click has mine then game over
        if(board[x][y] == 'M'){
            board[x][y] = 'X';
            return board;
        }

        if(board[x][y] == 'E'){
            int count = 0;
            //counting total adjacent mines
            for(int i=0;i<8;i++){
                int x0 = x + dirx[i];
                int y0 = y + diry[i];
                
                if(x0 >=0 && y0 >=0 && x0 < n && y0 < m) count += (board[x0][y0] == 'M');
            }
            
            //if there are adjacent mine then replace board[x][y] with 
            //count else recursively reveal all adjacent squares
            if(count > 0) board[x][y] = (count + '0');
            else{
                board[x][y] = 'B';
                for(int i=0;i<8;i++){
                    int x0 = x + dirx[i];
                    int y0 = y + diry[i];
                
                    if(x0 >=0 && y0 >=0 && x0 < n && y0 < m)
                        updateBoard(board, {x0, y0});
                }
            }
        }
        
        return board;
    }
};