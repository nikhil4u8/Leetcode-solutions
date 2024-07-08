class Solution {
public:
//TIME - O(2^n) SPACE - O(Nn)
    int ans = 0;
    void arrayCombination(vector<int>&nums, vector<int>temp, int idx, int curr_xor){
        if(idx == nums.size()-1){
            ans += curr_xor;
            return;
        }
        
        arrayCombination(nums, temp, idx+1, curr_xor);
        temp.push_back(nums[idx+1]);
        curr_xor ^= nums[idx+1];
        arrayCombination(nums, temp, idx+1, curr_xor);
    }
    int subsetXORSum(vector<int>& nums) {
        arrayCombination(nums, {}, -1, 0);
        return ans;
    }
};