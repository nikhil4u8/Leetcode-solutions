class Solution {
public:
    //TIME - O(N!) SPACE - O(N^2)
    bool check(vector<string>&board,int n,int x,int y){
        for(int i=x-1;i>=0;i--){
            if(board[i][y] == 'Q') return false;
        }
        
        for(int i=1;i<=min(x,n-y-1);i++){
            if(board[x-i][y+i] == 'Q') return false;
        }
        
        for(int i=1;i<=min(x,y);i++){
            if(board[x-i][y-i] == 'Q') return false;
        }
        
        return true;
    }
    void solve(vector<vector<string>>&board,int n,int row,vector<string>temp){
        if(row == n){
            board.push_back(temp);
            return;
        }
        
        string str = "";
        int t = n;
        while(t--) str += ".";
        temp[row] = str;
        
        for(int i=0;i<n;i++){
            temp[row][i] = 'Q';
            if(check(temp,n,row,i)) solve(board,n,row+1,temp);
            temp[row][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>board;
        vector<string>temp(n,"");
        
        solve(board,n,0,temp);
        
        return board;
    }
};