/*
Ques to ask :
    - Can the input be [INT_MIN, INT_MAX+1]?
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]].push_back(i);
        
        sort(nums.begin(), nums.end());
        int i=0,j=nums.size()-1;
        
        while(i<j){
            if(nums[i] + nums[j] == target){
                if(nums[i] == nums[j]) return {mp[nums[i]][0], mp[nums[i]][1]};
                return {mp[nums[i]][0],mp[nums[j]][0]};
            }else if(nums[i] + nums[j] > target) j--;
            else i++;
        }
        
        return {};
    }
};