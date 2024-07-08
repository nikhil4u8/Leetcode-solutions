class Solution {
public:
//TIME - O(N^2) SPACE - O(1)
/*
For each index i,we'll run a loop backward until min/max both are found,
if both are found then only we start to take subarray into account.
*/
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int count = 0;

        for(int i = 0;i<nums.size();i++){
            int j = i;
            bool max_reached = false, min_reached = false;

            while(j>=0){
                if(nums[j] > maxK || nums[j] < minK) break;
                if(nums[j] == maxK) max_reached = true;
                if(nums[j] == minK) min_reached = true;
                if(max_reached && min_reached) count++;
                j--;
            }
        }

        return count;
    }

//TIME - O(N) SPACE - O(1)
/*
Consider value at each index and count valid subarrays from 
left side. Valid subarrays will contain indices of latest seen 
minK , maxK and begin at start.If current value is less than 
minK or greater than maxK, new subarray starts from next index.
*/
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int last_min = -1, last_max = -1;
        int last_invalid_idx = -1;

        for(int i=0;i<nums.size();i++){
            if(nums[i] > maxK || nums[i] < minK){
                last_min = -1;
                last_max = -1;
                last_invalid_idx = i;
                continue;
            }

            if(nums[i] == maxK) last_min = i;
            
            if(nums[i] == minK) last_max = i;
            
                  
            if(last_min != -1 && last_max != -1)
                count += min(last_min,last_max)-last_invalid_idx;
        }

        return count;
    }
};