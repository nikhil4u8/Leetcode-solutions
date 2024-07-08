class Solution {
public:
//TIME - O(N) SPACE - O(1)
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() <= 1) return true;

        int increasing = 0;

        for(int i=1;i<nums.size();i++){
            //skipping equal numbers
            if(nums[i] == nums[i-1]) continue;
            //finding if the order is increasing or decreasing
            if(increasing == 0) increasing = nums[i] >= nums[i-1] ? 1 : -1;
            
            //comparing numbers based on the order
            if((increasing == 1 && nums[i] >= nums[i-1]) ||
               (increasing == -1 && nums[i] <= nums[i-1])) continue;
            return false;
        }
        return true;
    }
};