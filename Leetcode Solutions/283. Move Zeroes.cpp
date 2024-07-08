/*
Sol :
BEST APPROACH
=> Swaping : [TIME - O(N) SAPCE - O(1)]
    - Traverse the array & maintain 2 pointer i/j, when nums[i] is non 
    zero then swap number at ith / jth index and increment jth idx.
*/
class Solution {
public:
//TIME - O(N) SAPCE - O(1)
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while(i < nums.size()){
            if(nums[i] != 0) swap(nums[i], nums[j++]);
            i++;
        }
    }
};