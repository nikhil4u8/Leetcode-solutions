class Solution {
public:
    //RECURSIVE
//     vector<vector<int>>dp = vector<vector<int>>(1001, vector<int>(1001, 0));
//     int LCS(string x, string y, int n, int m){
//         if(n == 0 || m == 0) return dp[n][m] = 0;
        
//         if(x[n-1] == y[m-1]) 
//             return dp[n][m] = 1 + LCS(x, y, n-1, m-1);
//         return dp[n][m] = max(LCS(x, y, n-1, m), LCS(x, y, n, m-1));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         return LCS(text1, text2, text1.length(), text2.length());
//     }
    //TOP-DOWN
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(text1[i-1] == text2[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
};