class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xor_ = 0;
        for(int i=0;i<nums.size();i++) xor_ ^= nums[i];
        return xor_;
    }
};