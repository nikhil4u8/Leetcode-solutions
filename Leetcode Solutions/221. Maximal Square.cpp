class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int> > dp(n,vector<int>(m,0));
        int max_square = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1; j>=0; j--){
                if(i == n-1 or j == m - 1){
                    dp[i][j] = matrix[i][j] - '0';
                }else{
                    if(matrix[i][j] == '0'){
                        dp[i][j] = 0;
                    }else if(matrix[i][j] == '1'){
                        dp[i][j] = 1 + min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1]));
                    }
                }
                max_square = max(max_square,dp[i][j]);
            }
        }
        return max_square * max_square;
    }
};