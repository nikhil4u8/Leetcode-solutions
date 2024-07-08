/*
Ques to ask :
    - What if K = 0?

Sol : 
=> Expanding window : [TIME - O(M*K) SPACE - O(1)]
-> M : no of window of 1s, K : max number of flips
    - For each window of only 1's expand window leftward and rightwards both 
    until k zero's are encountered, them find maximum length of newly 
    generated window. Then move to next window of only 1's

=> Using Deque : [TIME - O(N) SPACE - O(N)]
    - Using a deque to store upto k zeros, when the size of deque > k, then 
    start popping out 0s from deque and increment left pointer until subarray 
    contains no more than k zeros i.e size of deque == k. 
    - Meanwhile maintain max len of subarray too.

BEST APPROACH
=> Two Pointer : [TIME - O(N) SPACE - O(1)]
    - Instead of using a deque in above approach, we can maintain a counter 
    to count no of zeros so far. If counter > k, then start moving left ptr 
    and decrementing counter until the subarray contains no more than k zeros 
    i.e counter == k.
    - Keep track of max len of subarray too.

Follow up : 
    - What if input is a infinite stream? 
        -> same method as this one.
        
Edge case : [0,0,0,0]
*/
class Solution {
public:
//BEST APPROACH
//Two pointer
//TIME - O(N) SPACE - O(1)
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, n = nums.size(), tempK = 0;
        int left = 0, right = 0;

        while(right < n){
            //if encounter 0 => decrement tempK
            if(nums[right] == 0) tempK++;
            //if tempK become > K i.e more zeros than expected, so start 
            //incrementing left ptr and removing zeros
            while(tempK > k && left <= right){
                tempK -= nums[left] == 0 ? 1 : 0;
                left++;
            }
            //keeping track of max subarray size
            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};