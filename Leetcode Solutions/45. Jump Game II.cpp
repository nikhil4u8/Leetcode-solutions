
class Solution {
public:
    int jump(vector<int>& nums) {
        int max_jump = nums[0];
        int steps_left = nums[0];
        int jump = 0;
        
        if(steps_left == 0 || nums.size() == 1) return 0;
        
        for(int i=1;i<nums.size();i++){
            max_jump = max(max_jump, i+nums[i]);
            steps_left--;
            
            if(steps_left == 0){
                steps_left = max_jump - i;
                if(i == nums.size()-1) return jump+1;
                if(steps_left == 0) return 0;
                jump++;
            }
        }
        
        return jump+1;
    }
};