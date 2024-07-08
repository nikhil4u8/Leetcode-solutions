/*
Ques to ask:
    - Which diagonal to traverl? From R to L or L to R?
    - What to return when matrix is empty?

Sol :
=> Diagnol traversal

BEST APPROACH
=> Row wise traversal : [TIME - O(N) SPACE - O(1)]
    - Simply traverse every row, and compare every element (i,j) to (i-1,j-1) element

Follow up:
    - What if at a time only 1 row of matrix can be loaded in memory?
        -> Row wise traversal (our sol)
    - What if at a time only partial row can be loaded into the memory?
        -> Split the matrix vertically into several sub-matrices, while each sub-matrix should have one column overlapped. Repeat the same method in follow-up 1 for each sub-matrix.
*/
class Solution {
public:
//TIME - O(N) SPACE - O(1)
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[i].size();j++){
                if(matrix[i][j] != matrix[i-1][j-1]) return false;
            }
        }

        return true;
    }
};