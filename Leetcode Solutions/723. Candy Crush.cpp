//Brute Force
//take a vector to store all indexes which need to be removed
//Traverse board, row wise then col wise and add all the points in vector
//then mark all of them as 0 and shift all 0 in starting

/*
Ques to ask :-
    - Do we need to crush all matching candies at same time, or we can crush only one candy at a time?
    - What if board[i][j] == 0
*/


//Mark all the number which needs to be removed as negative
//TIME - O(N*M) SPACE - O(1)
class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size(), count = 0;

        //Marking all possible drops as negative, if it has previous 2 similar num in a row/col
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp = board[i][j];
                if(temp == 0) continue;

                if(i>1 && abs(board[i-1][j]) == abs(temp) && abs(board[i-2][j]) == abs(temp)){     
                    board[i][j] = -abs(temp);
                    board[i-1][j] = -abs(temp);
                    board[i-2][j] = -abs(temp);
                    count++;
                }
                if(j>1 && abs(board[i][j-1]) == abs(temp) && abs(board[i][j-2]) == abs(temp)){
                    board[i][j] = -abs(temp);
                    board[i][j-1] = -abs(temp);
                    board[i][j-2] = -abs(temp);
                    count++;
                }
            }
        }

        if(count == 0) return board;

        //starting from last row, first col and accumulating all number which are +ve i.e are not dropping
        for(int i=0;i<m;i++){
            int k = n-1;
            for(int j=n-1;j>=0;j--){
                if(board[j][i] > 0){
                    board[k][i] = board[j][i];
                    k--;
                }
            }
            while(k >= 0) board[k--][i] = 0;
        }

        //recursively calling func again, in case there are new matches in row/col
        return candyCrush(board);
    }
};

class Solution {
public:
    //Intution - Mark all the nodes which need to removed as negative of board[i][j] and then drop them
   //TIME - O((N*M)^2) SPACE - O(N+M)
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int n = board.size();
        if(n==0) return board;
        int m=board[0].size();
        
        while(1){
                int count = 0;
                //vertical traversal and marking all points as -abs(board[i][j])
                //which are repeating more than thrice at a time
                for(int i=0;i<m;i++){
                   vector<int>dp(n,0);
                   dp[0] = 1;
                   for(int j=1;j<n;j++){
                      if(abs(board[j][i]==board[j-1][i]) && 
                         board[j][i]!=0 && board[j-1][i]!=0) dp[j] = dp[j-1];
                         dp[j]++;
                    }

                    for(int j=n-1;j>=0;){
                        if(dp[j]>=3){
                           int t = dp[j];
                           while(t--){ board[j][i] = -abs(board[j][i]); j--;}
                        }else j--;
                    }
                }
            //Horizontal traversal
                for(int i=0;i<n;i++){
                   vector<int>dp(m,0);
                   dp[0] = 1;
                   for(int j=1;j<m;j++){
                      if(abs(board[i][j])==abs(board[i][j-1]) && 
                         board[i][j]!=0 && board[i][j-1]!=0) dp[j] = dp[j-1];
                         dp[j]++;
                    }

                    for(int j=m-1;j>=0;){
                        if(dp[j]>=3){
                           int t = dp[j];
                           while(t--){ board[i][j] = -abs(board[i][j]); j--;}
                        }else j--;
                    }
                }
            //GRAVITY I.E FALLING STATE
                for(int i=0;i<m;i++){
                  int k=n-1;
                  for(int j=n-1;j>=0;j--){
                    if(board[j][i]>0) board[k--][i] = board[j][i];
                    if(board[j][i]<0) count++;
                  }
                  while(k>=0) board[k--][i] = 0;
                }
            
            if(count==0) return board;
         }
        
        return board;
    }
};