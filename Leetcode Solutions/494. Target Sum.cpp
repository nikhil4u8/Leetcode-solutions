/*
Ques to ask :
    - Can array contains 0? If yes, then is '1+0' & '1-0' considered 
    different exp?

Sol :
=> Recursive : [TIME - O(2^N) SPACE - O(N) -> depth of recursive tree]
    - Traverse the array & for every index, we've 2 choice +nums[i] or 
    -nums[i] & we'll also maintain result so far (which is sum of num 
    until i-1 idx) & call recrusive fun for both variation (+num[i],
    -num[i]) & once we reach end of array, check if resSoFar == target, 
    if it is then increment count.

=> Recursion with Memo : [TIME - O(N*T) SPACE - O(N*T)]
-> T : Sum of nums array
-> N : len of nums array
    - Memosize the above sol using a map which will store 
    {idx -> {resSoFar, count}}
*/
class Solution {
public:
//Approach - 2
//Recursion with memo
//TIME - O(N*T) SPACE - O(N*T)
    unordered_map<int,unordered_map<int, int>>mp;
    int findTargetSumWays(vector<int>& nums, int target, int idx = 0) {
        if(idx == nums.size()) return target == 0;

        if(mp.find(target) != mp.end() && 
            mp[target].find(idx) != mp[target].end()) return mp[target][idx];


        return mp[target][idx] = findTargetSumWays(nums, target+nums[idx], idx+1) 
        + findTargetSumWays(nums, target-nums[idx], idx+1);
    }

//Approach - 1
//Recursion only
//
    int count = 0;
    unordered_map<int, int>mp;
    void generateExpression(vector<int>&nums, int idx, int target, int resSoFar){
        if(idx == nums.size()){
            if(resSoFar == target) ++count;
            return;
        }

        generateExpression(nums, idx + 1, target, resSoFar + nums[idx]);
        generateExpression(nums, idx + 1, target, resSoFar - nums[idx]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        generateExpression(nums, 0, target, 0);
        return count;
    }
};