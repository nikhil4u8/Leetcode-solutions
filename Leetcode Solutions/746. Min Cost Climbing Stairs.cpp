class Solution {
public:
    vector<int>dp = vector<int>(1001, -1);
    //DP[n] represent what would be the cost to end up on step n
    //DP[n] = cost[n-1] + min(minCost(n-1), minCost(n-2));
    //DP[n] will be cost at current step + min among cost at last 2 steps from where jump can be made
    int minCost(vector<int>&cost, int n){
        if(n < 0) return 0;
        if(n == 0) return dp[n] = cost[0];
        if(n == 1) return dp[n] = cost[1];
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = cost[n] + min(minCost(cost, n-1), minCost(cost, n-2));
    }
    int minCostClimbingStairs(vector<int>& cost){
        int n = cost.size();
        return min(minCost(cost, n-1), minCost(cost, n-2));
    }
};