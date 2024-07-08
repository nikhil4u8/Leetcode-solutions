/*
Ques to ask :
    - Can sum of subarray goes beyond int values?

Sol :
=> Brute Force : [TIME - O(N^2) SPACE - O(1)]
    - Generate all possible subarray using two FOR loops & by fixing ith 
    pointer & moving jth pointer & find subarray with sum = k & update 
    maxLen variable with length of subarray accordingly.


BEST APPROACH
=> Using Map : [TIME - O(N) SPACE - O(N)]
    - Instead of calculating sum of subarray again & again, we can 
    precompute a prefix sum array & use that to find subarray sum in above 
    approach.
    - A better approach is to traverse array & for every jth idx find a 
    element in prefixSum array at ith idx (i<j) with val = Sum - k. So 
    that SUM[i,j] = SUM[0,j]-SUM[0,i]
    - Now, since we've to traver in prefixSum array to find such element, 
    so a better approach could be to use a map instead to make search in 
    O(1) complexity.
    - Meanwhile keeping track of maxLen too.

Follow up:
    - How to find the minimum size?
        -> update index in map whenever a duplicate sum if found
    - Find the max length of subarray whose sum >= k?
        -> Naive way is to use two for-loops with O(n2) time complexity,
*/
class Solution {
public:
//TIME - O(N) SPACE - O(N)
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long long int, long long int>mp;
        mp[0] = -1;
        long long int sum = 0, maxLen = 0;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];

            if(mp.find(sum-k) != mp.end()) 
                maxLen = max(maxLen, i - mp[sum-k]);
            
            //don't apply this to solve Follow up - 1
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }

        return maxLen;
    }
};