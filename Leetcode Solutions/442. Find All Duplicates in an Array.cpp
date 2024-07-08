//Approach 1 - Sort and Compare Adjacent Elements (TIME - O(NlogN) SPACE - O(!))
//Approach 2 - Store seen elements in set/map (TIME - O(N) SPACE - O(N))
//Approach 3 - Mark visited element in input array itself (TIME - O(N) SPACE - O(1))
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        //[1,1,2] -> [-1,1,1] 
        /*mark all the index of element present as negative
        if nums[index] is positive that means either that element
        doesn't exist or has appeared in 2 multiples
        
         Notice that if an element x occurs just once in the array, 
         the value at index abs(x)-1 becomes negative and remains 
         so for all of the iterations that follow.
        */
        for(int i=0;i<nums.size();i++)
            nums[abs(nums[i]) - 1] *= -1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i]) - 1] > 0){
                ans.push_back(abs(nums[i]));
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        
        return ans;
    }
};