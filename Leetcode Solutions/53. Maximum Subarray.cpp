class Solution {
public:
    //Time - O(n) space - O(n)
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(),ans=INT_MIN;
        vector<int>left(n);
        
        for(int i=0;i<n;i++){
            if(i-1>=0 && left[i-1]>=0) left[i] = left[i-1];
            left[i] += nums[i];
        }
        
        int temp=0;
        for(int i=n-1;i>=0;i--){
            if(!(i+1<n && temp>=0)) temp=0;
            temp += nums[i];
                
            ans = max(ans,temp);
        }
        
        return ans;
    }
    //Kadane's Algo
    //time - O(N) space - O(1)
    int maxSubArray(vector<int>& nums){
        int curr_sum=nums[0],maxi=nums[0];
        
        for(int i=1;i<nums.size();i++){
            curr_sum = max(nums[i],curr_sum+nums[i]);
            maxi = max(maxi,curr_sum);
        }
        return maxi;
    }
    //Divide and Conquer
    //time - O(NlogN) space - O(logN)->recursive stack
    int solve(int left,int right,vector<int>&nums){
        if(left>right) return INT_MIN;
        
        int mid = left + (right-left)/2;
        int curr = 0,best_left_sum = 0,best_right_sum=0;
        
        for(int i=mid-1;i>=left;i--){
            curr += nums[i];
            best_left_sum = max(best_left_sum,curr);
        }
        
        curr = 0;
        for(int i=mid+1;i<=right;i++){
            curr += nums[i];
            best_right_sum = max(best_right_sum,curr);
        }
        
        int res = nums[mid]+best_left_sum+best_right_sum;
        
        int left_half = solve(left,mid-1,nums);
        int right_half = solve(mid+1,right,nums);
        
        return max({res,left_half,right_half});
    }
    int maxSubArray(vector<int>& nums){
        return solve(0,nums.size()-1,nums);
    }

***Follow-up
    1.if endless stream of number is given
        - use kadane algo
    2.starting and ending Index of subarray
    3.Find the subarray within an array (containing at least k number) which has the largest sum.

2.
int maxSubArray(vector<int>& nums){
        int n = nums.size();
        vector<pair<int,int>>dp(n,0);
        dp[0].first = nums[0];
        dp[0].second = 0;
         
        for(int i=1;i<nums.size();i++){
            if(dp[i-1].first + nums[i] > nums[i]){
                dp[i].first = dp[i-1].first + nums[i];
                dp[i].second = dp[i-1].second;
            }else{
                dp[i].first = nums[i];
                dp[i].second = i;
            }
            if(maxi < dp[i].first){
                maxi = max(maxi,dp[i].first);
                start = dp[i].second;
                end = i;
            }
        }
        return {start,end};
}
3.
int maxSubArray(vector<int>& nums){
        int n = nums.size();
        vector<pair<int,int>>dp(n,0);
        dp[0].first = nums[0];
        dp[0].second = 0;
         
        for(int i=1;i<nums.size();i++){
            if(dp[i-1].first + nums[i] > nums[i]){
                dp[i].first = dp[i-1].first + nums[i];
                dp[i].second = dp[i-1].second;
            }else{
                dp[i].first = nums[i];
                dp[i].second = i;
            }
            if(i-dp[i].second+1>=k)  maxi = max(maxi,dp[i].first);
        }
        return maxi;
}
