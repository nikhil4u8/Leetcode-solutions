class Solution {
public:
// TIME - O(2^n * n) SPACE - O(2^n * n)
    set<vector<int>>st;
    void generate(vector<int>&nums, int idx, vector<int>temp){
        if(temp.size() >= 2)
            st.insert(temp); 

        if(idx == nums.size()) return;
        if(temp.size() == 0){

            for(int i=idx;i<nums.size();i++){
                if(i>0 && nums[i] == nums[i-1]) continue;
                temp.push_back(nums[i]);
                generate(nums, i+1, temp);
                temp.pop_back();
            }
            return;
        }

        generate(nums, idx+1, temp);

        int last = temp[temp.size()-1];
        if(last <= nums[idx]){
            temp.push_back(nums[idx]);
            generate(nums, idx+1, temp);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        generate(nums, 0, {});
        return vector(st.begin(), st.end());
    }
};