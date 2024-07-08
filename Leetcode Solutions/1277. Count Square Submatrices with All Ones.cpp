class Solution {
public:
    //time - O(n*m) space - O(1)
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    int temp = INT_MAX;
                    if(i-1>=0 && j-1>=0) 
                        temp = min({temp,matrix[i-1][j-1],matrix[i][j-1],matrix[i-1][j]});
        
                    if(temp!=INT_MAX)
                       matrix[i][j] += temp;
                    count += matrix[i][j];
                }        
            }
        }
        
        return count;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 || j == 0){
                    count += matrix[i][j];
                    continue;
                }
                int mini = INT_MAX;
                mini = min({matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]});
                
                if(matrix[i][j] != 0)
                    matrix[i][j] += mini;          
                count += matrix[i][j];
            }
        }
        
        return count;
    }
};
//Follow - up
//Count rectangler + square Submatrices with All Ones
//Maximum area of rectangle having all ones
//Largest Rectangle in histogram