//TIME - O(N) SPACE - O(N)
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int>mp;
        
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        
        int count = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i].length() > target.length()) continue;
            
            string first_str = target.substr(0, nums[i].length());
            string last_str = target.substr(nums[i].length());
            
            if(first_str == nums[i]){
                count += mp[last_str];
                if(first_str == last_str) count--;
            }
        }
        
        return count;
    }
};