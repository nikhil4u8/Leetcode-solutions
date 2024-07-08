class Solution {
public:
    vector<vector<int>>dp = vector<vector<int>>(1001, vector<int>(1001, -1));
    int longestCommonSubarray(vector<int>&nums1, vector<int>&nums2, int x, int y, int res){
        if(x == 0 || y == 0) return dp[x][y] = res;
        
        if(dp[x][y] != -1) return dp[x][y];
        
        int maxi = 0;
        if(nums1[x-1] == nums2[y-1])
            maxi = longestCommonSubarray(nums1, nums2, x-1, y-1, res + 1);
        
        maxi = max(maxi, max(longestCommonSubarray(nums1, nums2, x-1, y, 0), 
                             longestCommonSubarray(nums1, nums2, x, y-1, 0)));
        return dp[x][y] = maxi;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //return longestCommonSubarray(nums1, nums2, nums1.size(), nums2.size(), 0);
        
        int n = nums1.size();
        int m = nums2.size();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        int maxi = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 0;
                maxi = max(maxi, dp[i][j]);
            }
        }
        
        return maxi;
    }
};