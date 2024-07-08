// To find max subarray -> find max subarray || Total - find min subarray
//Case 1 :- Finding a maximum sum subarray inside array
//Case 2 :- Total - Finding a minimum sum subarray inside array (min sum != total otherwise subarray wont include any element in it)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN, ans_min = INT_MAX, total = 0;

        for(int i=0;i<n;i++) total += nums[i];

        int curr_max = 0, curr_min = 0;

        for(int i=0;i<nums.size();i++){
            curr_max = max(nums[i], nums[i] + curr_max);
            curr_min = min(nums[i], nums[i] + curr_min);

            ans = max(ans, curr_max);
            ans_min = min(ans_min, curr_min);
        }

        if(ans_min != total) ans = max(ans, total-ans_min);

        return ans;
    }
};
//Case 1 - When subarray is inside array
//Case 2 - When subarray is forming from cyclic array
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = INT_MIN;
        int curr_sum = 0, total_sum = 0, zero = 0;
        //Normal Kadane algo for handing case 1
        for(int i=0;i<nums.size();i++){
            //if previously curr_sum is -ve then this equation is discarding that
            curr_sum = max(curr_sum + nums[i], nums[i]);
            ans = max(ans, curr_sum);cout<<ans<<" ";
            total_sum += nums[i];
            if(nums[i] == 0) zero++;
        }
        
        curr_sum = 0;
        
        for(int i=0;i<nums.size();i++){
            curr_sum = min(curr_sum + nums[i], nums[i]);
            if(curr_sum != total_sum || (curr_sum == total_sum && zero > 0))
                ans = max(ans, total_sum - curr_sum);
        }
        
        return ans;
    }
};