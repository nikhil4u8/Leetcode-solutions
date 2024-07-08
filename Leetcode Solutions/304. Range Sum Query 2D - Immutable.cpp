/*
Sol :
=> Brute Force : [TIME - O(N*M) O(N*M) SPACE - O(1)]
    - Run 2 FOR loop to traverse through all the required element & return 
    sum

=> Using Row as Prefix Sum : [TIME - O(N*M) O(N) SPACE - O(N*M)]
    - For each row of matrix, we precompute sum of that row until that
    col, and while returning we loop through all the required row of 
    region, and add (sum[row][col2] - sum[row][col1 - 1]) & return the 
    addition

BEST APPROACH
=> Storing sum of all element in a square in lower right block
-> [TIME - O(N*M) O(1) SPACE - O(N*M)]
    - Create a matrix named regionSum of equivalent len of matrix i.e N*M
    - If we closly observe, every rectangle is made of sum of 2 rect - 
    sum of common rect, so using this we precompute regionSum
    - Every block of regionSum will contain sum of all the element of 
    block from [0,0] to [row, col]
    - RegionSum[r][c] = mat[r][c] - regionSum[r-1][c] - regionSum[r][c-1] 
    + regionSum[r-1][c-1]
*/
class NumMatrix {
public:
//BEST APPROACH
//TIME - O(N*M) O(1) SPACE - O(N*M)
    vector<vector<int>>regionSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        regionSum = vector<vector<int>>(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                regionSum[i][j] += matrix[i][j];
                if(i-1 >= 0) regionSum[i][j] += regionSum[i-1][j];
                if(j-1 >= 0) regionSum[i][j] += regionSum[i][j-1];
                if(i-1 >= 0 && j-1 >= 0) 
                    regionSum[i][j] -= regionSum[i-1][j-1]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = regionSum[row2][col2];
        if(col1 - 1 >= 0) ans -= regionSum[row2][col1 - 1];
        if(row1 - 1 >= 0) ans -= regionSum[row1 - 1][col2];
        if(row1 - 1 >= 0 && col1 - 1 >= 0) ans+=regionSum[row1-1][col1-1];
        return ans;
    }
};