class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>dp(numRows);
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1},{1,1}};
        
        dp[0] = {1};
        dp[1] = {1,1};
        
        for(int i=2;i<numRows;i++){
            vector<int>temp(i+1,0);
            temp[0] = 1;
            temp[i] = 1;
           for(int j=1;j<i;j++)
               temp[j] = dp[i-1][j] + dp[i-1][j-1];
            dp[i] = temp;
        }
        
        return dp;
    }
};