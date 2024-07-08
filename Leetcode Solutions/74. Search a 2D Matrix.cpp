/*
Sol :
=> Using Binary Search in row : [TIME - O(N*logM) SPACE - O(1)]
-> N : row & M : col
    - Travel down the row and apply binary search if the end element of 
    the matrix is > then the target

BEST APPROACH
=> Traversing from top right : [TIME - O(N+M) SPACE - O(1)]
    - To reduce search space, we need to eliminate some rows & col so that 
    search space gets reduced & time complexity too.
    - We've not used sorted col to our advantage yet. If we start 
    traversing from top right, then we can check if our num can be found 
    in that col or not, if it's not found then definately in prev col, if 
    it's found then move down one row & check if num can be found in row 
    or not.
*/
class Solution {
public:
    //TIME - O(N+M) SPACE - O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int i = 0,j=m-1;
        
        while(i<n && j>=0){
            if(matrix[i][j] == target) return true;
            
            if(matrix[i][j] > target) j--;
            else i++;
        }
        
        return false;
    }
};