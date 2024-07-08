class Solution {
public:
    //TOP-DOWN
    //Time - O(f*d) as there are (d x target) states of dp and we are doing O(f) work in each of the states. 
    //Time for recursion without dp, it will be O(f^d).
    //Space - O(d*f)
    int mod = 1000000007;
    long long int count_ways(int d,int f,int target,vector<vector<int>>&dp){
        if(target == 0 && d>=1) return dp[d][target] = 0;
        if(d==1) return dp[d][target] = target<=f;
        
        if(dp[d][target] != -1) return dp[d][target];
        
        long long int ways = 0;
        for(int i=1;i<=min(f,target);i++) ways += count_ways(d-1,f,target-i,dp);
        
        ways %= mod;
        return dp[d][target] = ways;
    }
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>>dp(d+1,vector<int>(target+1,-1));
        return count_ways(d,f,target,dp);
    }
    
    //Bottom-up
    //TIME - O(f*d*target) SPACE - O(d*target)
    int numRollsToTarget(int d, int f, int target) {
        int m=1000000007;
        vector<vector<int> > dp(d+1, vector<int>(target+1, 0));
        dp[0][0]=1;
        for(int i=1; i<=d; i++){
            for(int j=1; j<=target; j++){
                for(int k=1; k<=min(f,target); k++){
                        dp[i][j]=((dp[i][j]%m)+(dp[i-1][j-k]%m))%m;
                }
            }
        }
        return dp[d][target];
    }
    //Time - O(d*f*target)  Space - O(target)
    int numRollsToTarget(int d, int f, int target) {
        
        int dp[target + 1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int i=1;i<=d;i++){
            for(int j = target; j >= 0; j--){
                dp[j] = 0;
                for(int k = 1;k<=f;k++){
                    dp[j] += j >= k ? dp[j - k] : 0;
                    dp[j] = dp[j]%mod;
                }
            }
        }
        return dp[target];
        
    }
    //Time - O(d*target) Space - O(target)
    int numRollsToTarget(int d, int f, int target) {
      vector<int>dp(target+1,0);
      dp[0] = 1;
        
      for (int i=1;i<=d;i++) {
          vector<int>newDp(target+1,0);
          long long int sum = 0;
          for (int j=1;j<=target;j++) {
              sum += dp[j - 1];
              if (j>f) sum -= dp[j - f - 1];
              newDp[j] = (int)(sum % 1000000007);
          }
          dp = newDp;
      }
      return dp[target];
  }
};