/*
Similar Ques : 
    - Find kth missing positive number in sorted array
        -> Ref 1539. Kth Missing Positive Number
    - Kth missing element in sorted array (num can be negative).
        -> Ref. 1060. Missing element in sorted array
*/
class Solution {
    //TIME - O(logN) SPACE - O(1)
    public int findKthPositive(int[] arr, int k) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // If number of positive integers
            // which are missing before arr[pivot]
            // is less than k -->
            // continue to search on the right.
            if (arr[pivot] - mid - 1 < k) left = mid + 1;
            else right = mid - 1;
        }

        // At the end of the loop, left = right + 1,
        // and the kth missing is in-between arr[right] and arr[left].
        // The number of integers missing before arr[right] is
        // arr[right] - right - 1 -->
        // the number to return is
        // arr[right] + k - (arr[right] - right - 1) = k + left
        return left + k;
    }
}