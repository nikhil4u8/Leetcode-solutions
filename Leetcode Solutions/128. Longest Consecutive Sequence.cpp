class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        sort(nums.begin(),nums.end());
        
        int res = 1, maxi = 1, last_index=0;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]) continue;
            
            if(nums[i] == nums[last_index] + 1) maxi++;
            else maxi = 1;
    
            last_index = i;
            res = max(res,maxi);
        }
        
        return res;
    }
};