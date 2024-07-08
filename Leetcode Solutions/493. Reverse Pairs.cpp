class Solution {
public:
    //TIME - O(N^2) SPACE - O(1)
    int reversePairs(vector<int>& nums) {
        int count = 0;
        
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if((double)((double)nums[i]/2)>(double)nums[j]) count++;
            }
        }
        
        return count;
    }
    
};