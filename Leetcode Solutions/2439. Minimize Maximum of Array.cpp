class Solution {
public:
//TIME - O(N) SPACE - O(N)
/*
The best we can do is to reduce nums[i] to the average of array nums[0, i].

*/
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<long long int>prefix_sum(n, 0);

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) continue;

            prefix_sum[i] = nums[i];
            if(i > 0) prefix_sum[i] += prefix_sum[i-1];

            ans = max(ans, (int)ceil((double)prefix_sum[i]/((double)i+1)));
        }

        return ans;
    }
};