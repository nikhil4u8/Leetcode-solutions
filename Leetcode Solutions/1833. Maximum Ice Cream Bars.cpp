class Solution {
public:
//TIME - O(NlogN) SPACE - O(1)
//Using Greedy Approach
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        for(int i=0;i<costs.size();i++){
            if(costs[i] > coins) return i;
            coins -= costs[i];
        }

        return costs.size();
    }
//TIME - O(Coins*N) SPACE - O(Coins*N)
//Using LCS approach
    vector<vector<int>>dp;
    int maximumIceCream(vector<int>&costs, int coins, int n){
        if(n == 0 || coins == 0) return dp[n][coins] = 0;

        if(dp[n][coins] != -1) return dp[n][coins];

        if(costs[n-1] <= coins)
            return dp[n][coins] = max(1 + maximumIceCream(costs, coins - costs[n-1], n-1), maximumIceCream(costs, coins, n-1));

        return dp[n][coins] = maximumIceCream(costs, coins, n-1);
    }
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        dp = vector<vector<int>>(n+1, vector<int>(coins+1, -1));
        return maximumIceCream(costs, coins, n);
    }
};