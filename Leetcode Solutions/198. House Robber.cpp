class Solution {
public:
    //TIME - O(N) SPACE - O(N)
    int rob(vector<int>& nums) {
        int n = nums.size(),maxi=0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        
        vector<int>dp(n,0);
        
        dp[0] = nums[0];
        dp[1] = nums[1];
        maxi = nums[0];
        
        for(int i=2;i<n;i++){
            dp[i] = maxi+nums[i];
            maxi = max(maxi,dp[i-1]);
        }
        
        return *max_element(dp.begin(),dp.end());
    }
    //TIME - O(N) SPACE - O(1)
    int rob(vector<int>& nums) {
        int n = nums.size(),maxi=0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        
        int second_last=nums[0],first_last=nums[1];
        maxi = nums[0];
        
        for(int i=2;i<n;i++){
            second_last = maxi+nums[i];
            maxi = max(maxi,first_last);
            first_last = second_last;
        }
        
        return max(maxi,first_last);
    }
};

***FOLLOW-UP
    1.What if the input could also include non-positive values?
    2.Solve for a matrix of houses?
    3.Solve for a graph of houses?