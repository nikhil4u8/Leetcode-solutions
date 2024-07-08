class Solution {
public:
    int minCost(vector<int>&days, vector<int>&cost, int day, int temp_cost, int n){
        if(day >= days[n-1]) return temp_cost;
        
        int mini = INT_MAX;
        if(find(days.begin(), days.end(), day) != days.end()){
            mini = min({mini, minCost(days, cost, day+1, temp_cost+cost[0], n),
                       minCost(days, cost, day+7, temp_cost + cost[1], n),
                       minCost(days, cost, day+30, temp_cost + cost[2], n)
                       });
        }
        
        return mini;
    }
    //TIME - O(N*365) SPACE - O(365)
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(days[n-1]+1, 0);
        
        for(int i=1;i<=days[n-1];i++){
            if(find(days.begin(), days.end(), i) != days.end())
                dp[i] = min({dp[max(0,i-1)] + costs[0], dp[max(0,i-7)] + costs[1], dp[max(0,i-30)] + costs[2]});
            else dp[i] = dp[i-1];
        }
        
        return dp[days[n-1]];
    }
};