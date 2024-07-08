/*
Ques to ask:
    - Do we've duplicate elements? 
        -> if it not then we need fileter duplicates from our answer.
    - Is there any fix order to return output?
    - Can a subset be empty? like []?

Sol:
=> Backtracking : [TIME - O(N*2^N) SPACE - O(N)]
-> TC EXPLANATION SEE BELOW
    - For each element in nums, we've 2 choices wheather to include it in 
    array or not to include it, so first we include num[idx] & generate 
    all possible subset & store it, then we'll pop back and exclude 
    nums[idx] & generate all subset & store them

Follow up:
    - If nums contain duplicates?
        -> check if temp vector is already present in res or not
        -> Ref : 90. Subsets II
*/
class Solution {
public:
    vector<vector<int>>ans;
    void generateAllSubset(vector<int>&nums, vector<int>temp, int idx){
        ans.push_back(temp);

        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
            generateAllSubset(nums, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        generateAllSubset(nums, {}, 0);
        return ans;
    }
};
/*
TC EXPLANATION
Since for every element we've choices so 2^N combination & since we're 
traversing the array too after that so O(N) for that.
*/