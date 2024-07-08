/*
Ques to ask : 
    - Can array have no elements? What if both array are empty?
    - Are both array sorted?

Sol : 
=> Merge both array : [TIME - O(N+M*log(N+M) SPACE - O(max(N, M))] 
    - Merge both array in single array + sort new array + find median and 
    return it.

=> Two Pointer : [TIME - O(N+M) SPACE - O(1)]
    - Initialize 2 pointer, one pointer to array 1 and other to array 2
    - Move pointer that correspond to smaller value forward at each step 
    until half of the total number of elements are processed.
    - Calculate and return median based on values pointed by i & j.

BEST APPROACH
=> Binary Search : [TIME - O(log(min(n, m))) SPACE - O(1)]
    - Median exist in middle of the array, so if we find first half of 
    array then we'll know what could be the median
    - We can do BS in smaller array to select first half of the array. 
    Say we've formed first half of array with first t number from num1 and 
    rest (n+m)/2 - t from num2, then if this array is really first half 
    of the merged sorted array then max_first_half < min_second_half.
    - If above condition is true, then we found our first/second half of 
    array
    - If above consition if false, then we've to remove the max num from 
    first half of array & compensate rest of element from second array.
    - Do this until condition max_first_half < min_second_half is 
    satisfied.
*/
class Solution {
public:
//BEST APPROACH
//Binary search
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n == 0 && m == 0) return 0;
        if(n == 0) return ((double)nums2[(m-1)/2] + (double)nums2[m/2])/2;
        if(m == 0) return ((double)nums1[(n-1)/2] + (double)nums1[n/2])/2;

        //nums1 should be smallest
        if(n > m) return findMedianSortedArrays(nums2, nums1);
        //finding how much element of first half array will belong to 
        //nums1 / nums2
        int left = 0, right = n;
        while(left < right){
            int i = (left + right) / 2;
            int j = (n + m)/2 - i;

            if(nums1[i] < nums2[j-1]) left = i + 1;
            else right = i;
        }
        
        int first = left;
        int second = (n + m) / 2 - left;
        //shorterLeft = lastElement of first half array in nums1
        //sorterRight = first element of second half array in nums1
        double shorterLeft = first == 0 ? INT_MIN : nums1[first - 1];
        double shorterRight = first == n ? INT_MAX : nums1[first];
        
        //longerLeft = lastElement of first half array in nums2
        //longerRight = first element of second half array in nums2
        double longerLeft = second == 0 ? INT_MIN : nums2[second - 1];
        double longerRight = second == m ? INT_MAX : nums2[second];
        
        if((n + m) % 2 == 1) 
            return min(shorterRight, longerRight);
        return (max(shorterLeft, longerLeft)+min(shorterRight, longerRight))/2;
    }
};