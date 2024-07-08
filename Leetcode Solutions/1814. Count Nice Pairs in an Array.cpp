//TIME - O(N) SPACE - O(N)
class Solution {
public:
    int mod = 1000000007;
    int rev(int num){
        string num_str = to_string(num);
        int ans = 0;
        
        for(int i=num_str.length()-1;i>=0;i--){
            ans = ans*10 + (num_str[i] -'0');
        }
        
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<long long int, long long int>mp;
        for(int i=0;i<nums.size();i++){
            int diff = nums[i] - rev(nums[i]);
            mp[diff]++;
        }
        
        long long int count = 0;
        
        for(auto it : mp){
            if(it.second >= 2) count += (((it.second%mod)*((it.second-1)%mod))/2)%mod;
        }
        
        return count % mod;
    }
};