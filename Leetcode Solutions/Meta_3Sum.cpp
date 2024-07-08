/*
Ques to ask :
    - Does the array contains duplicates?
    - Can we use one index multiple times?
    - Is the array already sorted?

Sol :
    - Sort the array, fix one number and traverse in rest of 
    the array, and do 2Sum. At every point avoid duplicate 
    number by skipping them.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        int len = nums.size();
        
        for(int i=0;i<len-2;i++){
            if(i!=0 && nums[i] == nums[i-1]) continue;
            int j=i+1,k=len-1;
            
            while(j<k){
                if(j!=i+1 && nums[j] == nums[j-1]){
                    j++;
                    continue;
                }
                if(k!=len-1 && nums[k] == nums[k+1]){
                    k--;
                    continue;
                }
                
                if(nums[i] + nums[j] + nums[k] == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }else if(nums[i] + nums[j] + nums[k] > 0) k--;
                else j++;
            }
        }
        
        return ans;
    }
};