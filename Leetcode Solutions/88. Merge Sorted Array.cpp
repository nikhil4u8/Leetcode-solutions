/*
Ques to ask :
    - Are both array sorted?
    
Sol :
=> Array + Sorting : [TIME - O((N+M)log(N+M)) SPACE - O(1)]
    - Fill up all ending zeros in nums1, with all element of nums2 & sort.

BEST APPROACH
=> Array + Two pointer : [TIME - O(N+M) SPACE - O(1)]
    - Take 2 pointer i & j (i = m-1, j = n-1) to traverse both array from 
    backward & start comparing element at i/j index, place the larger 
    element in end of nums1 & decrease corresponding i/j pointer and move 
    one point backward.
    - Continue doing this until we have iterated through all the elements 
    in nums2, if elements left in nums1, we don't need to do anything 
    becoz they're already in correct place
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(N+M) SPACE - O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = n+m-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]) nums1[k] = nums1[i--];
            else nums1[k] = nums2[j--];
            k--;
        }

        while(j>=0) nums1[k--] = nums2[j--];
    }
};