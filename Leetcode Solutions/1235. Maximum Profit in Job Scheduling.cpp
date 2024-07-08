class Solution {
public:
    vector<int>dp = vector<int>(50001, -1);
    int nextIdx(vector<vector<int>>&jobs, int end_time, int idx){
        for(int i=idx+1;i<jobs.size();i++){
            if(jobs[i][0] >= end_time) return i;
        }
        return jobs.size();
    }
    int maxProfit(vector<vector<int>>&jobs, int curr_idx){
        if(curr_idx == jobs.size()) return dp[curr_idx] = 0;
        
        if(dp[curr_idx] != -1) return dp[curr_idx];
        
        int include = jobs[curr_idx][2] + maxProfit(jobs, nextIdx(jobs, jobs[curr_idx][1], curr_idx));
        int exclude = maxProfit(jobs, curr_idx+1);
        
        return dp[curr_idx] = max(include, exclude);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>jobs;
        
        for(int i=0;i<startTime.size();i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        
        sort(jobs.begin(), jobs.end());
        
        return maxProfit(jobs, 0);
    }
};