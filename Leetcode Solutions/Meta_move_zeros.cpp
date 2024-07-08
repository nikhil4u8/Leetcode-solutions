class Solution {
    public:
    void moveZeroes(vec& nums) {
        int i=0, k = nums.size()-1;
        while (i < nums.size()){
            if(nums[i] == 0){
                while(k>=0 && nums[k] != 0) k--;

                if(i >= k) break; 
                swap(nums[i], nums[k--]);
            }
            i++;
        }
        
        sort(nums.begin(), nums.begin()+i);
    }
};