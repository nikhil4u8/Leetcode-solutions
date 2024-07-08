class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        vector<vector<int>>dp(n, vector<int>(k, 0));
        
        int mini = INT_MAX, second_min = INT_MAX;
        for(int i=0;i<n;i++){
            int temp_mini = mini, temp_second_min = second_min;
            mini = INT_MAX;
            second_min = INT_MAX;
            
            for(int j=0;j<k;j++){
                dp[i][j] += costs[i][j];
                if(i != 0){
                    if(dp[i-1][j] == temp_mini) dp[i][j] += temp_second_min;
                    else dp[i][j] += temp_mini;   
                }
                if(mini > dp[i][j]){
                    second_min = mini;
                    mini = dp[i][j];
                }else if(second_min > dp[i][j])
                    second_min = dp[i][j];
            }
        }
        
        return mini;
    }
};