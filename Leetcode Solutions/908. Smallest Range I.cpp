//TIME - O(1) SPACE - O(1)
//If we can bring big/small no to the mid, then every other no in array can come to mid as well, and ans will be 0, else we need to decrement max no and increment min no as much as possible. 
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int diff = nums[n-1] - (nums[0] + nums[n-1])/2;
        if(diff <= k) return 0;
        return nums[n-1] - nums[0] - 2*k;
    }
};
