class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>odd;
        vector<int>even;
        
        for(int i=0;i<nums.size();i++){
            if(i%2 == 0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        
        sort(even.begin(), even.end());
        sort(odd.rbegin(), odd.rend());
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(i%2 == 0) nums[i] = even[j];
            else nums[i] = odd[j++];
        }
        
        return nums;
    }
};