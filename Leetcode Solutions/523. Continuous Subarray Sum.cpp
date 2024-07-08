/*
/*
Ques to ask :   
    - Can K == 0? K is negative int?
    - If array has <2 elements?
    - Is 0 considered a multiple of K?

Sol :
=> Brute Force - [TIME - O(N^2) SPACE - O(1)]
    - Use 2 FOR loop to find every possible subarray & use second FOR 
    loop to find it's sum & check if it's same as K or not. 
    - Basically we've to find if SUM[i, j] = k

BEST APPROACH
=> Using Map - [TIME - O(N) SPACE - O(N)]
    - Instead of using a FOR loop for finding sum of subarray, we can 
    maintain a map or prefix sum array to store running sum.
    - Traverse the array & keep track of running sum % k of elements. If 
    we find that a runningSum % k at idx j is already seen previously at 
    idx i, then when they're subtracted, then sum of subarray (i, j] will 
    become multiple of k. Ofc we'll check size of subarray as well.
    - We'll prefer using Hashmap over prefix sum array, since to find if 
    there already exist a runningSum%K in array then we've to traverse 
    whole prefix_sum array, but in Hashmap this operation will be O(1).

Follow up:
    - Find subarray having maximum sum?
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //sum%k -> first idx at which this sum occured
        unordered_map<int, int>mp;
        int runningSum = 0;

        for(int i=0;i<nums.size();i++){
            runningSum += nums[i];
            //if subarray is [0, i]
            if(runningSum % k == 0 && i >= 1) 
                return true;
            if(mp[runningSum % k] > 0 && i + 1 - mp[runningSum % k] >= 2) 
                return true;
            
            //if runningSum % k is not present in map
            if(mp[runningSum % k] == 0) mp[runningSum % k] = i+1;
        }

        return false;
    }
};