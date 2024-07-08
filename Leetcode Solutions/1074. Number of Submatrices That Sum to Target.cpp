class Solution {
public:
    //Approach-1
    //run 2 loop for all possible combination of rows and then inside it run 2 loop for all possible 
    //combination of col, and then find sum b/w (r2,c2),(r2,c1),(r1,c2),(r1,c1)
    
    //TO STORE SUM
    //  1.To store sum->prefix_sum[i][j] = matrix[i][j]+prefix_sum[i][j-1]
    //  2.Divide a square into 4 parts then sum
    
    //Approach-2
    //run 2 for loop for possible combinations of rows then ques converted into Subarray sum equal K
    //TIME - O(N*N*M)  SPACE - O(N*M)
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>>prefix_sum(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
              prefix_sum[i+1][j+1]=matrix[i][j]+prefix_sum[i][j+1]+prefix_sum[i+1][j]-prefix_sum[i][j];
        }
        
        int count = 0;
        
        for(int r1=0;r1<n;r1++){
            for(int r2=r1;r2<n;r2++){
                unordered_map<int,int>mp;
                for(int c1=0;c1<m;c1++){
                    int curr_sum = prefix_sum[r2+1][c1+1]-prefix_sum[r1][c1+1];
                    
                    if(curr_sum == target) count++;
                    
                    count += mp[curr_sum-target];
                    mp[curr_sum]++;
                }
            }
        }
        
        return count;
    }
};