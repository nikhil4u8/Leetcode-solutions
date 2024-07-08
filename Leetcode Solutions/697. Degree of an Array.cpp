class Solution {
public:
//time - O(N) SPACE - O(N)
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>>mp;
        int len = INT_MAX, maxi = 0;

        for(int i=0;i<nums.size();i++){
            int start, end, freq = 0;

            if(mp.find(nums[i]) == mp.end()){
                start = i;
                end = i;
                freq = 1;
            }else{
                start = mp[nums[i]][0];
                end = i;
                freq = 1 + mp[nums[i]][2];
            }

            mp[nums[i]] = {start, end, freq};
            
            if(maxi <= freq){
                if(maxi == freq) len = min(len, end - start + 1);
                else len = end - start + 1;
                maxi = freq;
            }
        }

        return len;
    }
};