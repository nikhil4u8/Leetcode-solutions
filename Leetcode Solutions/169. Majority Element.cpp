class Solution {
public:
    //Approach - 1 (time - O(n^2) space - O(1))
    //Brute force - by running two for loop and count the frequency of each 
    //element and find maximum count of frequency
    
    //Approach - 2 (time - O(n) space - O(n))
    //use a hash map to store freq of elements
    
    //Approach - 3 (time - O(nlogn))
    //sort the list and count freq
    
    //Approach - 4 (time - O(nlogn) space - O(logn))
    //To find the majority in whole array, we divide array into 2 parts and 
    //repeatedly find the majority in the respective part and then constructively 
    //decide the majority while combining the parted arrays.
    int countInRange(vector<int> &nums, int num, int lo, int hi)
    {
        int count = 0;
        for(int i = lo ; i <= hi ; i++)
        {
            if(nums[i] == num)
                count++;
        }
        return count;
    }
    
    int majorityElementInRange(vector<int> &nums, int lo, int hi)
    {
        if(lo == hi)
            return nums[lo];
        int mid = lo + (hi-lo)/2;
        int leftMajority = majorityElementInRange(nums, lo, mid);
        int rightMajority = majorityElementInRange(nums, mid+1, hi);
        
        if(leftMajority == rightMajority) return leftMajority;
        int leftCount  = countInRange(nums, leftMajority, lo, mid);
        int rightCount = countInRange(nums, rightMajority, mid+1, hi);
        return leftCount > rightCount ? leftMajority : rightMajority;
    }
    
    int majorityElement(vector<int>& nums) {
        return majorityElementInRange(nums, 0, nums.size()-1);
    }


    //Approach - 4 (Time - O(n) space - O(1))
    //Basic idea of the algorithm is if we cancel out each occurrence of an 
    //element e with all the other elements that are different from e then e 
    //will exist till end if it is a majority element. Below code loops through 
    //each element and maintains a count of the element that has the potential 
    //of being the majority element. If next element is same then increments the 
    //count, otherwise decrements the count. If the count reaches 0 then update 
    //the potential index to the current element and sets count to 1.
    int majorityElement(vector<int>& nums) {
        int maxi=nums[0],count=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=maxi) count--;
            else count++;
            if(count==0){
                maxi = nums[i];
                count++;
            }
        }
        
        return maxi;
    }
};

//Follow-up
//what if array is sorted
//then choose middle element - (time - O(1))