class Solution {
public:
    int isPossible(vector<int>&nums, int target){
        int sum = 0;
        int m = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] > target) return INT_MAX;
            sum += nums[i];
            if(sum > target){
                if(sum == nums[i]) return INT_MAX;
                sum = nums[i]; 
                m++;
            }
        }
        
        return m+1;
    }
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int sum = 0, mini=INT_MAX;
        
        for(int i=0;i<n;i++){
            sum += nums[i];
            mini = min(mini, nums[i]);
        }
        
        int start = mini, end = sum;
        int ans = INT_MAX;
        
        while(start <= end){
            int mid = (start + end)/2;
            int temp = isPossible(nums, mid);
            //cout<<start<<" "<<end<<" "<<mid<<" "<<temp<<"\n";
            
            if(temp <= m){
                ans = min(ans, mid);
                end = mid - 1;
            }else start = mid + 1;
            
        }
        
        return ans;
    }
};