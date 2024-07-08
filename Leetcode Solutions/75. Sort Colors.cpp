class Solution {
public:
    //Approach-1 -> count all zero and two and then place then accordingly -> two pass sol
    //Approach-2 -> while traversing keep 2 pointer and if 0 appeared than swap with first pointer n increment it
    void sortColors(vector<int>& nums) {
        int i=0,j=nums.size()-1,k=0,len=nums.size();

        while(k<=j){
            if(nums[k]==0) swap(nums[i++],nums[k++]);
            else if(nums[k]==2) swap(nums[j--],nums[k]);
            else k++;
        }    
    }
};