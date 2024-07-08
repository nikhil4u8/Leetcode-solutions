/*
QUES TO ASK :-
    - Is the input [2,2,4] valid?
    - Can nums[i] = 0?
    - Is the array sorted?

SOLUTION :-
=> Brute force [TIME - O(N^3) | SPACE - O(1)]
    - Trying every possible combination of i,j,k

=> Fixing 2 num and Binary Search for one [TIME - O(N^2.logN) | Space - O(logN)]
    - We can fix i and for j belongs to (i+1, end), and now in the remaining array (index k) from (j+1, end) do a binary search to check the index of number > nums[i]+nums[j], and then ans += k - j - 1;

=> Best Approach [3 Sum approach] [TIME - O(N^2) | SPACE - O(1)]
    - Fix the largest element, say nums[i] where nums[k] <= nums[j] <= nums[i], now we need to find pair nums[j]+nums[k] > nums[i].

EDGE CASES :-
    - Nums[i] = 0


WHY TRAVERSE FROM RIGHT TO LEFT?
=> Ans : To avoid considering 0 as side
=> If one side of triangle is zero, let the smallest side is zero, 
so a = 0. To form a valid triangle, a + b > c [where c is largest side]
<=> 0 + b > c <=> b > c, which is incorrect. Since c is the largest side.
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();

        //Fixing ith to be largest element
        //TIME - O(N)
        for(int i=n-1;i>1;i--){
            //looping j from i-1 to 0, kinda 2 sum problem
            int j = i-1, k = 0;
            //TIME - O(N) -> since it's kinda linear traversal
            while(k<j){
                //if sum is greater then count all element b/w j&k
                if(nums[j] + nums[k] > nums[i]){
                    ans += j - k;
                    j--;
                }else k++; //otherwise increment k to increase sum
            }
        }

        return ans;
    }
};