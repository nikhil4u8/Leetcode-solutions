class Solution {
public:
    //dp[i][j] = points[i][j] + max(dp[i-1][....] - abs(j-...))
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 0) return 0;
        
        int m = points[0].size();
        long long ans = 0;
        
        long long left_max = INT_MIN, right_max = INT_MIN;
        vector<vector<long long>>dp(n, vector<long long>(m, INT_MIN));
        
        for(int i=0;i<n;i++){
            left_max = INT_MIN;
            right_max = INT_MIN;
            for(int j=0;j<m;j++){
                if(i == 0) dp[i][j] = points[i][j];
                else{
                    left_max = max(left_max, dp[i-1][j] + j);
                    dp[i][j] = max(dp[i][j], points[i][j] - j + left_max);   
                }
            }
            for(int j=m-1;j>=0;j--){
                if(i == 0) dp[i][j] = points[i][j];
                else{
                    right_max = max(right_max, dp[i-1][j] - j);
                    dp[i][j] = max(dp[i][j], points[i][j] + j + right_max);
                }
            }
        }
        
        for(int i=0;i<m;i++) ans = max(ans, dp[n-1][i]);
        
        return ans;
    }
};