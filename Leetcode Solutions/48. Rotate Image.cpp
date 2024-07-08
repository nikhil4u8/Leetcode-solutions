class Solution {
public:
    //Rotate in pair of 4 elements
    //We can iterate over each group of four cells and rotate them.
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i=0;i<n/2;i++){ //used to traverse in square layers
            for(int j=i;j<n-1-i;j++){ //used to traverse inside each square layer
                //using example
                int temp1 = matrix[j][n-i-1]; // temp = 5
            
                matrix[j][n-i-1] = matrix[i][j]; // 5 -> 15
                int temp2 = matrix[n-i-1][n-j-1]; //temp2 = 11
                
                matrix[n-i-1][n-j-1] = temp1; // 11->5
                temp1 = matrix[n-j-1][i]; // temp1 = 16
                
                matrix[n-j-1][i] = temp2; // 16->11
                
                matrix[i][j] = temp1; //15->16
            }
        }
    }
};
//Follow up
//what if N*M rectangle is given
//sol
Just take the transpose of matrix and then revese each row or swap 
class Solution {
public:
    void transpose(vector<vector<int>>&A,int m,int n)
    {
        for(int i=0;i<m;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                swap(A[i][j],A[j][i]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        transpose(matrix,m,n);
        
        for(int i=0;i<m;++i)
        {
            
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};