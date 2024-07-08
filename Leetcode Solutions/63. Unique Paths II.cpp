/*
Ques to ask : 
    - What if obstacle is placed at starting and ending point?
    - What if there doesn't exist any path from (0,0) to (n-1, m-1) then 
    what to return?
    - What to return in case input = [[1]]
    - Can we modify grid?
        -> If no then build a seperate array to store distance
Sol : 
=> Recursive : [TIME - O(2^(N*M)) SPACE - O(len of path) -> recursive 
stack]
    - We'll start from (0,0) & recursively build up our solution ie for 
    each cell we'll go right / down to cell which aren't obstacle and 
    once we reach (n-1,m-1) then we'll keep track of minPathLen variable 
    & return it in end

=> Memo : [TIME - O(N*M) = no of states SPACE - O(N*M)]
    - In recursion there will be many deduplication so we'll store our 
    output in a seperate array.

BEST APPROACH
=> Bottom up DP : [TIME - O(N*M) SPACE - O(1)]
    - Since we can only move down and right, so for every cell we can 
    calculate unique path = uniquePath[i-1][j] + uniquePath[i][j-1] & in 
    end return uniquePath[n-1][m-1]

Follow up : 
    - What if the grid is huge and we've few obstacles only, so 
    calculating unique path will take O(N*M) time, can we do it in O(K^2) 
    where K is no of obstacle?

Similar Ques : 
    - Find unique path without obstacle 
        -> Ref : 62. Unique Paths
    - Find unique path with obstacles
        -> Ref 63. Unique Paths II
*/
class Solution {
public:
//BEST APPROACH
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(n == 0) return 0;
        int m = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;

        obstacleGrid[0][0]--;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j] != 1){
                    if(i>0 && obstacleGrid[i-1][j] != 1)
                        obstacleGrid[i][j] += obstacleGrid[i-1][j];
                    if(j>0 && obstacleGrid[i][j-1] != 1)
                        obstacleGrid[i][j] += obstacleGrid[i][j-1];
                }
            }
        }

        return -obstacleGrid[n-1][m-1];
    }
};

/*
Follow up : What to do in case of grid >>>> obstacles
Solution : 
    - Classical sol is of O(N*M) time, we've to do it in O(K^2) time
    - If there are 0 obstables, we've C(h + w - 2, h - 1) ways from (1, 1) 
    => (h , w). C denotes for combinations (like nC2)
    - Now we want to calculate how many bad ways are there, then 
    ans = C(h + w - 2, h - 1) - total badways.
    - If (r1, c1) is the starting obstcles, we've bad ways = (number of 
    ways without touching any obstacle from (1, 1) to 
    (r1, c1)) * C(h - r1 + w - c1, h - r1)
    - Total badways = sum(bad ways if each obstable as a staring obstcle)

DP way : [TTME : O(max(K^2),log(N+M)*(N+M)) SPACE : O(max(K^2),log(N+M)*(N+M))]
    - Since there can be many deduplication in above case, so we'll use 
    DP. Let dp[i] = num of ways from (1,1) to obstacle[i] without touching 
    any obstacles.
    - dp[i] = C(r1 + c1 - 2, r1 - c1) - Sum(dp[j]) if 
    obstacles[j].r <= obstacles[i].r and obstacles[j].c <= obstacles[i].c
    - Now, If (r1, c1) is the starting obstcles, we have 
    (dp[i]) * C(h - r1 + w - c1, h - r1) bad ways for each choosen 
    starting obstacle
*/