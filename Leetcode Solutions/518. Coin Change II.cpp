//TIME - O(N*AMOUNT) SPACE - O(N*AMOUNT)
class Solution {
public:
    //Recursion + Memo
//     vector<vector<int>>dp = vector<vector<int>>(5001, vector<int>(301, -1));
//     int solve(int amount, vector<int>& coins, int index){
//         if(amount == 0) return dp[amount][index] = 1;
//         if(amount !=0 && index == 0) return dp[amount][index] = 0;
        
//         if(dp[amount][index] != -1) return dp[amount][index];
        
//         if(amount >= coins[index-1])
//             return dp[amount][index] = solve(amount - coins[index-1], coins, index) + 
//                                        solve(amount, coins, index-1);
//         return dp[amount][index] = solve(amount, coins, index-1);
//     }
//     int change(int amount, vector<int>& coins) {
//         return solve(amount, coins, coins.size());
//     }
    //Top down
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        
        //can be converted to a 2*amount DP
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(j == 0) dp[i][j] = 1;
                else if(i == 0) dp[i][j] = 0;
                else if(j >= coins[i-1]) dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][amount];
    }
};