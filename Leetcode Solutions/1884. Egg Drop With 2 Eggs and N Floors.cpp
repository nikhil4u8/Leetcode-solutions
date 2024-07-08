class Solution {
public:
    long long min_drop(int n,int k,vector<vector<long long>>&dp){
        if(n<=0 || k<=0) return 0;
        if(n==1 || n==0 || k==1) return dp[n][k] = n;
    
        if(dp[n][k] != -1) return dp[n][k];
    
        int mini = INT_MAX,res;
        
        for(int x=1;x<=n;x++) {
            res = max(min_drop(x-1,k-1,dp),min_drop(n-x,k,dp));
            mini = min(mini,res);
        }
     
        return dp[n][k] = mini + 1;
    }
    int twoEggDrop(int n){
        vector<vector<long long>>dp(n+1,vector<long long>(3,-1));
        return min_drop(n,2,dp);
    }
};