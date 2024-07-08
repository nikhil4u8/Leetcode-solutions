/*
Ques to ask:
    - Is the array sorted?
    - We need to find element that are strictly increasing?
    - Can subseq contain <= 1 element?
*/
class Solution {
public:
//TIME - O(N) SPACE - O(1)
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLen = 0, tempLen = 1;
        //Traverse the string & find max continous array
        for(int i=1;i<nums.size();i++){
            if(nums[i] > nums[i-1]) tempLen++;
            else{
                maxLen = max(maxLen, tempLen);
                tempLen = 1;
            }
        }

        return max(maxLen, tempLen);
    }
};