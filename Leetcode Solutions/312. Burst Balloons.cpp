class Solution {
public:
    vector<vector<int>>dp = vector<vector<int>>(305, vector<int>(305, -1));
    //ith ballon burst => cost = nums[start-1]*nums[i]*nums[end+1]
    int maxCost(vector<int>&nums, int start, int end){
        if(start > end) return dp[start][end] = 0;
        
        if(dp[start][end] != -1) return dp[start][end];
        int ans = 0;
        // For all elements in the range i to j, we choose all of them one by one 
		// to make them the last balloon to be burst. 
        for(int k = start; k <= end; k++){
            // Burst the kth balloon after bursting (i, k - 1) and (k + 1, j) balloons
            // Recursively solve the left and right subproblems and add their contribution
            int temp_cost = nums[start-1] * nums[k] * nums[end+1] + 
                            maxCost(nums, start, k - 1) + maxCost(nums, k+1, end);
            // If this choice of k yields a better answer
            ans = max(ans, temp_cost);
        }
        
        return dp[start][end] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1, 1);
        
        int n = nums.size();
        
        return maxCost(nums, 1, n - 2);
    }
};
/*
If we burst the kth balloon in first chance, we'll get cost = nums[k-1] * nums[k] * nums[k+1]. Now coming to subproblem :- 
 => solve(nums, i, k - 1) , solve(nums, k + 1, j)

As balloon k is already burst, we solve subproblem from i to k-1 and k+1 to j. But then subproblem solve(nums, i, k-1) and solve(nums, k+1, j) are not independent since after bursting kth balloon, balloon k - 1 and k + 1 have become adjacent and they will need each other in order to calculate the profit.

So, as we saw that if we choose the kth balloon to be the first one to be burst, we can't make the subproblems independent. Let's try the other way round. We choose the kth balloon as the last one to be burst. Now the subproblems will become independent since (k - 1)th balloon and (k + 1)th balloon won't need each other in order to calculate the answer. (Try it out using pen and paper).

Now for each k starting from i to j, we choose the kth balloon to be the last one to be burst and calculate the profit by solving the subproblems recursively. Whichever choice of k gives us the best answer, we store it and return.
Important point to be noted here is that the balloons in the range (i, k - 1) and (k + 1, j) will be burst BEFORE kth balloon. So, when we burst the kth balloon, the profit will be nums[i - 1] * nums[k] * nums[j + 1] PROVIDED that index i - 1 and j + 1 are valid.
*/