/*
Ques to ask :
    - Is the array sorted?
    - What if target doesn't exist?

Sol :
=> Linear search : [TIME - O(N) SPACE - O(1)]
    - Linearly search in whole array to find first / last occurance

BEST APPROACH
=> Two pass Binary search : [TIME - O(2*logN) SPACE - O(1)]
    - Do 2 times binary search to find first and last occurance
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(2*logN) SPACE - O(1)
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int firstOccurance = -1, lastOccurance = -1;
        int start = 0, end = n-1;
        //finding first occurance
        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target) firstOccurance = mid;
            
            if(nums[mid] < target) start = mid + 1;
            else end = mid - 1;
        }

        start = 0;
        end = n-1;
        //finding last occurance
        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target) lastOccurance = mid;
            
            if(nums[mid] > target) end = mid - 1;
            else start = mid + 1;
        }

        return {firstOccurance, lastOccurance};
    }
};