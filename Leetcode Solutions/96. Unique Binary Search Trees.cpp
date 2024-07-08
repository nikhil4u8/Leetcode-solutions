class Solution {
public:
    int solve(int start,int end,vector<vector<int>>&dp){
        if(start>end) return 0;
        if(start == end) return dp[start][end] = 1;
        
        if(dp[start][end] != -1) return dp[start][end];
        
        int ans = 0;
        for(int i=start;i<=end;i++){
            int left = solve(start,i-1,dp);
            if(i-1<start) left = 1;
            int right = solve(i+1,end,dp);
            if(end<i+1) right = 1;
            
            ans += left*right;
        }
        
        return dp[start][end] = ans;
    }
    int numTrees(int n) {
        vector<vector<int>>dp(20,vector<int>(20,-1));
        return solve(1,n,dp);
    }
    //Recursive
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        
        return dp[n];
    }
};