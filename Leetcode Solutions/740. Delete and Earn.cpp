class Solution {
public:
    /*This problem is a variant of the house robber problem .
The house robber problem states that "the only constraint stopping you 
from robbing each of the house is that adjacent houses have security 
systems connected and it will automatically contact the police if two 
adjacent houses were broken into on the same night." Which means one 
cannot rob the adjacent house.

Recurrance Relation :-
f(i) = max ( f(i-1), f(i-2) + money(i) )
    */
    int deleteAndEarn(vector<int>& nums) {
         int n = 10001;
    
	//take the total sum by each number
        vector<int> sum(n, 0);
        vector<int> dp(n, 0);
    
        for(auto num: nums) sum[num] += num;
    
    
        dp[0] = 0;
        dp[1] = sum[1];
    
        //now apply the house robbing concept
        for(int i=2; i<n; i++)  dp[i] = max(dp[i-2] + sum[i], dp[i-1]);
    
        return dp[n-1];
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> values(n, 0);
        for (int num : nums)
            values[num] += num;

        int take = 0, skip = 0;
        for (int i = 0; i < n; i++) {
            int takei = skip + values[i];
            int skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }

    int deleteAndEarn(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        
        int n = mp.size();
        vector<int>dp(n, 0);
        int maxi = 0, ans = 0, i = 0, last = INT_MIN;
        
        for(auto num : mp){
            int key = num.first;
            int val = num.second;
            
            if(key != last+1 && i>0) maxi = max(maxi, dp[i-1]);
            dp[i] = key*val + maxi;
            if(i>0) maxi = max(maxi, dp[i-1]);
            
            ans = max(ans, dp[i]);
            last = key;
            
            i++;
        }
        
        return ans;
    }
};