class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        vector<int>dp(n, 0);
        
        for(int i=0;i<n;i++){
            int temp_max = 0;
            for(int j=i-1;j>=0;j--){
                if(nums[j] < nums[i])
                    temp_max = max(temp_max, dp[j]);
            }
            dp[i] = 1 + temp_max;
            maxi = max(maxi, dp[i]);
        }
        
        return maxi;
    }
};