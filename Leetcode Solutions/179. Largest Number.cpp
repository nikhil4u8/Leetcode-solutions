bool compare(int l, int r) {
    string str_l = to_string(l);
    string str_r = to_string(r);

    string s1 = str_l + str_r;
    string s2 = str_r + str_l;
    
    return s1 > s2;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        
        string ans = "";
        int i = 0;
        while(i<nums.size() && nums[i] == 0) i++;

        for(;i<nums.size();i++) ans += to_string(nums[i]);

        if(ans == "") return "0";

        return ans;
    }
};