/*
Approach - 
At ith place either we can have same or different paint as compared to (i-1)th index.
Number of ways to paint ith index = Number of ways to paint same paint as (i-1)th index + Number of ways to paint different paint as (i-1)th index.

num_way -> total number of ways to paint ith index
num_way_same -> total number of ways to paint i & i-1 index with same paint
num_way_diff -> total number of ways to paint i & i-1 index with different paint

num_ways[i] = num_way_same[i] + num_way_diff[i]
num_way_diff[i] = num_way[i-1]*(k-1)

For num_way_same[i] :-
since we don't want 3 consecutive paint, so we need to take different paint at (i-1) & (i-2) index, hence : 

num_way_same[i] = num_way_diff[i-1]*1 -> *1 is done as we have only one way to choose same paint
since num_way_diff[i] = num_way[i-1]*(k-1)

num_way_same[i] = num_way[i-1]*(k-1)

==> num_way[i] = num_way[i-1]*(k-1) + num_way[i-2]*(k-1) = (k-1)*(num_way[i-1] + num_way[i-2])
*/
class Solution {
public:
    //TIME - O(N) SPACE - O(N)
    int numWays(int n, int k) {
        if(n == 0) return 0;
        if(n == 1) return k;
        if(n == 2) return k*k;
        
        vector<int>dp(n+1, 0);
        dp[0] = 0;
        dp[1] = k;
        dp[2] = k*k;
        
        for(int i=3;i<=n;i++)
            dp[i] = (k-1)*(dp[i-1] + dp[i-2]);
        
        return dp[n];
    }
};