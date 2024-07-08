class Solution {
public:
    //BRUTE FORCE
    //Simply find min value
    //TIME - O(logN) SPACE - O(1)
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=n-1;
        
        while(i<=j){
            int mid = i + (j-i)/2;
            
            if(mid == 0){
                if(nums[mid]<=nums[n-1]) return nums[mid];
                i = mid+1;
            }else if(mid == n-1){
                if(nums[mid]<=nums[mid-1]) return nums[mid];
                j = mid-1;
            }
            else if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]) return nums[mid];
            else if(nums[mid]>nums[n-1]) i = mid+1;
            else j = mid-1;
        }
        
        return -1;
    }
};
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int i=0,j=len-1, mini = INT_MAX;
        
        while(i<=j){
            int mid = (i+j)/2;
            
            mini = min(mini,nums[mid]);
            if(nums[mid] >= nums[0] && nums[mid] >= nums[len-1])
                i = mid + 1;
            else j = mid - 1;
        }
        
        return mini;
    }
};