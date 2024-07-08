/*
Sol :
SAY THIS FIRST
- A winner will win if all the char in a row / col / diag are same as 
player char

=> Storing everything in matrix : [TIME - O(1) O(N + N + N) SPACE - O(N*N)]
    - Create a matrix & then when a player make a move, traverse through 
    the respective row, col & diag to check if all the char are same or 
    not, if it's same then that player wins if not same then move on

BEST APPROACH
=> Maintaining count of each row, col, diag in a vector
-> [TIME - O(1) O(1) SPACE - O(N)]
    - We don't need to keep track of entire n^2 board. We only need to 
    keep a count for each row, col & both diag. 
    - Each time when a player makes a move in {x,y}, we consider -1 for 
    player 1's move and +1 for player 2's move & increment count of 
    row[x], col[x], diag & anti diag & check if any of them is equal to 
    N / -N respectively.
*/
class TicTacToe {
public:
//TIME - O(1) O(1) SPACE - O(N)
    vector<int>rowSum, colSum;
    int diag1 = 0, diag2 = 0, N;
    TicTacToe(int n) {
        rowSum = vector<int>(n, 0);
        colSum = vector<int>(n, 0);
        N = n;
    }
    
    int move(int row, int col, int player) {
        if(player == 1){
            rowSum[row]++;
            colSum[col]++;
            if(row == col) diag1++;
            if(row + col == N - 1) diag2++;

            if(rowSum[row] == N || colSum[col] == N || 
                diag1 == N || diag2 == N)
                return 1;
        }else{
            rowSum[row]--;
            colSum[col]--;
            if(row == col) diag1--;
            if(row + col == N - 1) diag2--;

            if(rowSum[row] == -N || colSum[col] == -N || 
                diag1 == -N || diag2 == -N)
                return 2;
        }

        return 0;
    }
};