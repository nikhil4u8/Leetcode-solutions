/*
Ques to ask:
    - Is the array sorted?
    - Are elements in nums unique?
    - Can nums[i] > upper or nums[i] < lower?
    - Is there any specific order in which output should be returned?

Sol:
=> Linear Scan : [TIME - O(N) SPACE - O(1)]
    - Traverse the nums array & keep track of last visited number & check 
    if current number i.e nums[i] == nums[i-1] + 1 or not, if it is that 
    mean we've no missing num b/w 2 adjacent idx in nums, if it is not 
    then add the missing range b/w nums[i-1] & nums[i]
*/
class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>missingRange;
        int lastNum = lower-1, j = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] != lastNum + 1)
                missingRange.push_back({lastNum+1, nums[i]-1});

            lastNum = nums[i];
        }

        if(lastNum != upper) missingRange.push_back({lastNum + 1, upper});
        return missingRange;
    }
};