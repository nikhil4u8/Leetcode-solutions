/*
Ques to ask:
    - Is the array sorted?
    - Can sol have duplicate triplet having different indexes? Ex: [2,2,2,2], Ans = [{2(0),2(1),2(2)},{2(1),2(2),2(3)}]
    - We need to return index of triplets or triplet number itself?
    - Can the input be [INT_MIN, INT_MAX+1, 0]?

Sol :
=> Making all possible triplets : [TIME - O(N^3) SPACE - O(1)]
    - Make all possible triplets & find it's their sum is 0 or not, and 
    store the triplets in set<vector<int>> which is to avoid entering 
    duplicate triplet

BEST APPROACH
=> Making pairs using 2 pointer : [TIME - O(N^2) SPACE - O(1)]
    - We'll fix one idx & for remaining array take 2 pointer, pointing to 
    start / end & move them accordingly to the sum of the element
    - To avoid duplicates, before processing a num check if previous 
    processed num is same or not, if same then skip curr num

Edge case :
    - When duplicates are present.
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(N^2) SPACE - O(1)
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            //to avoid processing duplicate num
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int targetSum = -nums[i];
            int j = i+1, k = n-1;

            while(j < k){
                //to avoid processing duplicate num
                if(j != i+1 && nums[j] == nums[j-1]){
                    j++;
                    continue;
                }
                if(k != n-1 && nums[k] == nums[k+1]){
                    k--;
                    continue;
                }

                int sum = nums[j] + nums[k];

                //incrementing i/j as per the sum
                if(sum == targetSum){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }else if(sum > targetSum) k--;
                else j++;
            }
        }

        return ans;
    }
};