class Solution {
public:
    //METHOD-1 
    //TIME - O(N) with extra space
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n*2);
        
        for(int i=0;i<n;i++){
            res[i]=nums[i];
            res[i+n]=nums[i];
        }
        return res;
    }
    //METHOD-2
    //TIME - O(N) without extra space
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) nums.push_back(nums[i]);
        return nums;
    }
};