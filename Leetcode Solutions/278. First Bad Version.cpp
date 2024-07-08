/*
Ques to ask :
    - What is the range of N? from 0 or from 1?
    - What if no bad version exist?

Sol :
=> SAY THIS FIRST
    - Firstly, we've correct version, then a version became bad and after 
    that all versions are bad.
    - So we can assume it as a array having some 0 (indicating correct 
    version) and rest of elements as 1 (indicating bad version) in array.

=> Linear Search - [TIME - O(N) SPACE - O(1)]
    - Simply do a linear traversal for all N, and the first one which has 
    bad version return that N.

BEST APPROACH
=> Binary Search - [TIME - O(logN) SPACE - O(1)]
    - Instead of linearly traversing in sorted array, do binary search to 
    find first occurance of 1. 
*/
class Solution {
public:
    int firstBadVersion(int n) {
        int i = 0, j = n;
        while(i < j){
            int mid = i + (j-i)/2;
            if(isBadVersion(mid)) j = mid;
            else i = mid+1;
        }

        return j;
    }
};