class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, INT_MAX));
        
        for(int i=0;i<=amount;i++)
            dp[0][i] = INT_MAX - 1;
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(i == 1){
                    //dp[i][j] = j/coins[i-1]; 
                    if(j%coins[i-1] == 0) dp[i][j] = j/coins[i-1]; 
                    else dp[i][j] = INT_MAX-1;
                }else if(j >= coins[i-1])
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        if(dp[n][amount] >= INT_MAX - 1) return -1;
        return dp[n][amount];
    }
};