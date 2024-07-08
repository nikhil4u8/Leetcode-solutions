class Solution {
public:
    //Divide and conquer approach
    /*
    Dividing the array into 2 parts from every ith index and summing up the maximum profit from each array
    Time - O(N^2) SPACE - O(1)
    */
//     int Profit(vector<int>&prices, int start, int end, bool islast = false){
//         if(start >= end) return 0;
        
//         int mini = prices[start], max_profit = 0;
        
//         for(int i=start+1;i<=end;i++){
//             max_profit = max(max_profit,prices[i] - mini);
//             mini = min(mini, prices[i]);
//         }
        
//         if(islast) return max_profit;
        
//         int _max_profit = 0;
//         for(int i = start+1;i<end-1;i++){
//             int t1 = Profit(prices, start, i, true);
//             int t2 = Profit(prices, i+1, end, true);
//             _max_profit = max({_max_profit, t1 + t2});
//         }
//         return max(max_profit, _max_profit);
//     }
//     int maxProfit(vector<int>& prices) {
//         return Profit(prices, 0, prices.size()-1, false);
//     }
    /*
    Bi-directional DP
    TIME _ O(N) SPACE - O(N)
    */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        
        vector<int>left(n, 0);
        vector<int>right(n+1, 0);
        
        int left_min = prices[0];
        int right_max = prices[n-1];
        
        for(int i=1;i<prices.size();i++){
            left[i] = max(left[i-1], prices[i] - left_min);
            left_min = min(left_min, prices[i]);
            
            int r = n-i-1;
            right[r] = max(right[r+1], right_max - prices[r]);
            right_max = max(right_max, prices[r]);
        }
        
        int max_profit = 0;
        for(int i=0;i<n;i++){
            max_profit = max(max_profit, left[i] + right[i+1]);
        }
        
        return max_profit;
    }
};