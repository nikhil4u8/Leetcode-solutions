class Solution {
public:
    //TIME - O(logN)
    //This code will work for duplicates too
    int searchInsert(vector<int>& nums, int target) {
        int l=0,n=nums.size(),r=n-1;
        int index = -1;
        
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                index = mid;
                r = mid-1; 
            }else{
                index = mid+1;
                l = mid + 1;
            }
        }
        
        return index;
    }
};