class Solution {
public:
    //time - o(n) space - o(n)
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i]) != st.end()) return true;
            st.insert(nums[i]);
        }
        return false;
    }
    //time - o(nlogn) space - o(1)
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return false;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) return true;
        }
    return false;
    }
    //Time - O(nlogn) space - O(n)
    bool containsDuplicate(vector<int>& nums) {
        return set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};