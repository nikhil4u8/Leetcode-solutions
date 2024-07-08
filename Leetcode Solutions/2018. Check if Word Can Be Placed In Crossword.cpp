class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int len = word.length();
        int n = board.size();
        if(n == 0 && len == 0) return true;
        int m = board[0].size();
        
        bool verti = false, hori = false;
        if(len <= n) verti = true;
        if(len <= m) hori = true;
        
        if(verti){
            for(int i=0;i<m;i++){
                int index = 0;
                for(int j=0;j<n;j++){
                    if(board[j][i] == '#') index = 0; 
                    else if(board[j][i] != ' ' && board[j][i] != word[index]){
                        index = 0;
                        j++;
                    }else{
                        if(index == 0 && j>0 && board[j-1][i] != '#') continue;
                        index++;
                    }
                    if(index == len){
                        if((j<n-1 && board[j+1][i] == '#') || j==n-1)
                            return true;
                        index = 0;
                    }
                }
                index = 0;
                for(int j=n-1;j>=0;j--){
                    if(board[j][i] == '#') index = 0;
                    else if(board[j][i] != ' ' && board[j][i] != word[index]){
                        index = 0;
                        j--;
                    }else{
                        if(index == 0 && j<n-1 && board[j+1][i] != '#') continue;
                        index++;
                    }
                    if(index == len){
                        if((j>0 && board[j-1][i] == '#') || j==0)
                            return true;
                        index = 0;
                    }
                }
            }  
        }
        if(hori){
            for(int i=0;i<n;i++){
                int index = 0;
                for(int j=0;j<m;j++){
                    if(board[i][j] == '#') index = 0;
                    else if(board[i][j] != ' ' && board[i][j] != word[index]){
                        index = 0;
                        j++;
                    }else{
                        if(index == 0 && j>0 && board[i][j-1] != '#') continue;
                        index++;
                    }
                    if(index == len){
                        if((j<m-1 && board[i][j+1] == '#') || j==m-1)
                            return true;
                        index = 0;
                    }
                }
                index = 0;
                for(int j=m-1;j>=0;j--){
                    if(board[i][j] == '#') index = 0;
                    else if(board[i][j] != ' ' && board[i][j] != word[index]){
                        index = 0;
                        j--;
                    }else{
                        if(index == 0 && j<m-1 && board[i][j+1] != '#') continue;
                        index++;
                    }
                    if(index == len){
                        if((j>0 && board[i][j-1] == '#') || j==0)
                            return true;
                        index = 0;
                    }
                } 
            } 
        }
        
        return false;
    }
};