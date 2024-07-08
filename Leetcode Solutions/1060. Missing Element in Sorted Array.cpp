/*
Ques to ask :
    - From where counting is started?
    - If K == 0?
    
Sol : 
=> Linear traversal : [TIME - O(N) SPACE - O(1)]
    - Starting traversing linearly & add diff b/w 2 adjacent numbers in 
    nums, meanwhile subtract that diff from k until it reaches 0.
    - If diff >= k, then return nums[i] + k. If in end k is left then 
    return nums[end] + k

BEST APPROACH
=> Binary Search - [TIME - O(logN) SPACE - O(1)]
    - Perform Binary Search based on number of missing elements, 
    - First, calculate how many number are missing in a range = 
    (nums[end] - nums[start] + 1) - nums.len. If total missing num < k, 
    then we won't get kth missing element in that range, so we'll return 
    nums[end] + k.
    - If total missing num > k, then we'll find missing num inside nums
    - Using BS we'll find element from nums (nums[i], nums[i+1]) where kth 
    missing num could lie.

Similar Ques : 
    - Find kth missing positive number in sorted array
        -> Ref 1539. Kth Missing Positive Number
    - Kth missing element in sorted array (num can be negative).
        -> Ref. 1060. Missing element in sorted array
*/
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0, end = n-1;

        int complete_length = nums[end] - nums[start] + 1;
        int actual_length = n;
        // complete length - real length is missing number
        int missing = complete_length - actual_length;

        //if we want missing num which is beyong
        if(k > missing) return nums[end] + k - missing;

        while(start + 1 < end){
            int mid = start + (end - start)/2;
            complete_length = nums[mid] - nums[start] + 1;
            actual_length = mid - start + 1;
            //in b/w [start, end] this much num are missing
            missing = complete_length - actual_length;

            //is missing num are more than k then in this range we'll 
            //be able to find kth missing num
            if(missing >= k) end = mid;
            //This means in this range, we won't find kth element, so 
            //excluding this range & subtracting missing_count from k
            else{
                start = mid;
                k -= missing;
            }
        }

        return nums[start] + k;
    }
};