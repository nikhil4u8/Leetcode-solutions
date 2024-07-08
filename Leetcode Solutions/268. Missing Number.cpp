class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int temp_xor = 0,num_xor=0;
        
        for(int i=0;i<n;i++){
            temp_xor ^= nums[i];
            num_xor ^= i;
        }
        num_xor ^= nums.size();
        num_xor ^= temp_xor;
        
        return num_xor;
    }
};