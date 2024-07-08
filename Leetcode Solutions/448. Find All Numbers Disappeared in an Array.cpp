/*
Sol:
=> Using sort : [TIME - O(NlogN) SPACE - O(1)]
    - Sort the array, traverse array & find element which are missing

=> Using hash space : [TIME - O(N) SPACE - O(N)]
    - Maintain a extra visited array having numbers from 1-n & traverse 
    nums array & mark number in it visited in our array & in end return 
    the num which are not visited

BEST APPROACH
=> Store elements in correct position in-place : [TIME - O(N) SPACE - O(1)]
    - Traverse through the array & for each number mark it's corresponding 
    index (= nums[i] - 1) as -ve, this indicate that nums[i] is present 
    in array
    - After doing this, traverse the array again & check which indexes 
    have +ve num and those are the one who're missing.
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(N) SPACE - O(1)
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();++i)
            nums[abs(nums[i])-1] = -1*abs(nums[abs(nums[i])-1]);
        
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0)
                ans.push_back(i+1);
        }

        return ans;
    }
};