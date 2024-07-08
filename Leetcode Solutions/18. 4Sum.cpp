class Solution {
public:
//TIME - O(N^3) SPACE - O(1)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans; 

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0;i<n-3;i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1;j<n-2;j++){
                if(j != i+1 && nums[j] == nums[j-1]) continue;

                int k = j+1, l = n-1;
                long req_sum = target - (long)nums[i] - (long)nums[j];

                while(k < l){
                    int currK = nums[k], currL = nums[l];
                    long sum = (long)(currK + currL);

                    if(sum == req_sum){ 
                        ans.push_back({nums[i], nums[j], currK, currL});
                        while(k<l && nums[k] == currK) k++;
                        while(k<l && nums[l] == currL) l--;
                    }else if(sum > req_sum){
                        l--;
                        while(k<l && nums[l] == currL) l--;
                    }else{
                        k++;
                        while(k<l && nums[k] == currK) k++;
                    }
                }
            }
        }

        return ans;
    }
};