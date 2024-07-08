class Solution {
public:
    int mod = 1000000007;
    int countVowelPermutation(int n) {
        vector<vector<long long>>dp(n+1, vector<long long>(5, 0));
        dp[1] = {1,1,1,1,1};
        for(int i=2;i<=n;i++){
            dp[i][0] = ((dp[i-1][1] + dp[i-1][4])%mod + dp[i-1][2])%mod; //a
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;//e
            dp[i][2] = (dp[i-1][1] + dp[i-1][3])%mod; //i
            dp[i][3] = dp[i-1][2]%mod; //o
            dp[i][4] = (dp[i-1][3] + dp[i-1][2])%mod; //u
        }
        
        return (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4])%mod;
    }
};