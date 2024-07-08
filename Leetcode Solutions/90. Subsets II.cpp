/*
Ques to ask:
    - Can we've duplicate subset?
    - Is there any fix order to return output?
    - Can a subset be empty? like []?

Sol:
BEST APPROACH
=> Backtracking : [TIME - O(N*2^N) SPACE - O(N)]
-> TC EXPLANATION SEE BELOW
    - First sort the elements, so that while traversing array we can skip 
    duplicates
    - For each element in nums, we've 2 choices wheather to include it in 
    array or not to include it, so first we include num[idx] & generate 
    all possible subset & store it, then we'll pop back and exclude 
    nums[idx] & generate all subset & store them.

Follow up:
    - If nums doesn't duplicates?
        -> Ref : 78. Subsets
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(N*2^N) SPACE - O(N)
    vector<vector<int>>ans;
    void generateAllSubset(vector<int>&nums, vector<int>temp, int idx){
        ans.push_back(temp);

        for(int i=idx;i<nums.size();i++){
            if(i > idx && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            generateAllSubset(nums, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        generateAllSubset(nums, {}, 0);
        return ans;
    }
};
/*
TC EXPLANATION
Since for every element we've choices so 2^N combination & since we're 
traversing the array too after that so O(N) for that.
*/