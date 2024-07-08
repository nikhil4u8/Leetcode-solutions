/*
Ques to ask :
    - Can sum of subarray goes beyond int values?
    - If subarray sum is 0, then can we've empty subarray as a answer?
    - Can K be -ve / 0 ?
    - Is sum == 0, considered multiple of K?
    - Can nums[i] be +ve / -ve?

Sol :
=> BRUTE FORCE - [TIME - O(N^2) | SPACE - O(1)]
    - Consider every possible subarray & use second FOR loop to find 
    it's sum & check if it's same as K or not. 
    - Basically we've to find if SUM[i, j] = k

BEST APPROACH
=> Using Map - [TIME - O(N) | SPACE - O(N)]
    - Instead of using a FOR loop for finding sum of subarray, we can 
    maintain a map or prefix sum array to store running sum.
    - Traverse the array & keep track of running sum of elements. If we 
    find that a runningSum - k (at idx j) is seen previously at idx i, 
    then when they're subtracted, then sum of subarray (i, j] will 
    become equal to k.
    - We'll prefer using Hashmap over prefix sum array, since to find if 
    there already exist a runningSum - K in array then we've to traverse 
    whole prefix_sum array, but in Hashmap this operation will be O(1).

BEST APPROACH : only when nums contains +ve numbers
=> Using sliding window : [TIME - O(N) SPACE - O(1)]
    - Use a sliding window, and expand it until subarray sum reaches K,
    when it exceed k then remove first element from sliding window until
    sum becomes <= k & then start adding next elements until sum reached 
    K. Meanwhile maintain count of subarray too.

Follow up :
    - Print all the subarray with sum = K
    - What if nums contains only +ve integers, then do it in O(1) space?
        -> use sliding window approach
*/
class Solution {
public:
//  TIME - O(N) SPACE - O(N)
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int, int>mp;
        mp[0] = 1;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(mp.find(sum - k) != mp.end()) count += mp[sum - k];

            mp[sum]++;
        }

        return count;
    }
};

//FOLLOW UP
/*
Ques : Print all the subarray with sum = K
Ans : Instead of storing freq count, store the ending idx in map, and 
when sum-k is found, then store all pairs of {mp[sum-k][j], i}
*/
//FOLLOW UP : 2
//When nums contains only +ve int 
int subarraySum(vector<int>& nums, int k) {
    int i = 0, j = 0, n = nums.size(), windowSum = 0, subarrayCount = 0;

    while(j < n){
        windowSum += nums[j];
        if(windowSum == k) subarrayCount++;
        else if(windowSum > k){
            while(windowSum > k){
                windowSum -= nums[i];
                i++;
                if(windowSum == k){
                    subarrayCount++;
                    break;
                }
            }
        }
        j++;
    }
    return subarrayCount
}