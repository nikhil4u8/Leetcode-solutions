class Solution {
public:
//TIME - O(n) SPACE - O(1)
    int pivotIndex(vector<int>& nums) {
        int total = 0, currSum = 0;
        for(int i=0;i<nums.size();i++) total += nums[i];
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            if(currSum - nums[i] == total - currSum) return i;
        }

        return -1;
    }
};