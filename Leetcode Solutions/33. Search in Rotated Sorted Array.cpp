/*
Ques to ask : 
    - Can there be duplicate values
    - If element doesn't exist?

Sol :
    - Simply do a binary search, along with few conditions checks, 
    read conditions from code.
    - Find the peak element, then divide array in 2 part and search element
    in each part seperately. 
*/
class Solution {
public:
    //Approach-1 -> simply search in array
    //Approach-2 -> 3 pass Binary Search
    //Approach-3 -> One pass Binary Search
    //TIME - O(logN) SPACE - O(1)
    int search(vector<int>& nums, int target) {
        // mid - 6, tar - 7 => right (bada)
        // mid - 6, tar - 4, 0 => r/l (chota)
        // mid - 1, tar - 2, 4 => r/l (bada)
        // mid - 1, tar - 0 => left (chota)
        int start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = (start+end)/2;

            // to avoid duplicates
            // while (l<r and nums[l] == nums[l+1])
            // l++;
            // while (l<r and nums[r] == nums[r-1])
            // r--;
            if(nums[mid] == target) return mid;
            else if(nums[mid] >= nums[start]){
                if(target <= nums[mid] && target >= nums[start]) 
                    end = mid - 1;
                else start = mid + 1;
            }
            else{
                if(target >= nums[mid] && target <= nums[end]) 
                    start = mid + 1;
                else end = mid - 1;
            }
        }

        return -1;
    }
    //TIME - O(logN)
    int index = -1;
    int peak(vector<int>&nums){
        int n = nums.size();
        int i=0,j=n-1;
        
        while(i<=j){
            int mid = i + (j-i)/2;
            
            if(mid == 0){
                if(nums[mid]<=nums[n-1]) return mid;
                i = mid+1;
            }else if(mid == n-1){
                if(nums[mid]<=nums[mid-1]) return mid;
                j = mid-1;
            }
            else if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]) return mid;
            else if(nums[mid]>nums[n-1]) i = mid+1;
            else j = mid-1;
        }
        
        return -1;
    }
    void binary_search(vector<int>&nums,int start,int end,int target){
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                index = mid;
                return;
            }
            if(nums[mid]>target) end = mid-1;
            else start = mid+1;
        }
    }
    int search(vector<int>& nums, int target) {
        int peak_index = peak(nums);
        
        binary_search(nums,0,peak_index-1,target);
        binary_search(nums,peak_index,nums.size()-1,target);
        
        return index;
    }
};