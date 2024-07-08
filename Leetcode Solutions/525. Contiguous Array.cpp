/*
APPROACH 1 : BRUTE FORCE : [Time : O(n^2) Space : O(1)]

-The brute force approach is simple.
-We traverse the array using 2 loops.
-We start at i = 0 & traverse till the last index using loop 1 & loop 2 
traverses from i & traverses till the last index.
-We consider every possible subarray within the given array and count the 
number of zeros and ones in each subarray.
-Each time, the no. of zeroes & ones becomes equal we update the maxLength.

BEST APPROACH
APPROACH 2 : Using Hash Table : [Time : O(n) Space : O(N)]

-The appproach is same as that of the previous one.
-But here we use a map instead of an array of size 2n+1, because it's not 
necessary that we'll encounter all possible sums in between -n & +n.
-The array will store the indices for each new sum encountered & if a sum 
is already encountered it will determine the difference between the 2 
indices.
-At each index, it updates the maxLen of equal number of 0's & 1's.
Finally, we return maxLen.

*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0, maxLen=0;
        unordered_map<int, int> seen{{0, -1}};
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i]==1 ? 1 : -1;
            if(seen.count(sum)) maxLen = max(maxLen, i-seen[sum]);
            else seen[sum] = i;
        }
        return maxLen;
    }
};