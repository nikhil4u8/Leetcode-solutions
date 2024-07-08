/*
Ques to ask :
    - Both matrix are valid like dimension wise like matrix not of 0 dimension?

Sol :
=> Brute force : Matrix multiplication - [TIME - O(N*M*K) SPACE - O(1)]
    - Simple matrix multiplication using multiple for loop & storing 
    result in another matrix. This is done using 3 for loops, 
    mat1Row->mat1Col->mat2Row

=> Optmized brute force : [TIME - O(N*M*K) SPACE - O(1)]
    - We can skip last for loop in above approach, if mat1[i][j] == 0 or 
    mat2[j][k].

BEST APPROACH : Done to save memory / disk space along with run time reduction
=> Compressed matrix - [TIME - O(N*M*K) SPACE - O(M*K + K*N)]
    - Since in a sparse matrix we've majority num to be 0, so we'll store 
    all non zero num from both matrix in a vector or map. Since if any of 
    the value in matrix is 0, then it's useless to multiple.
    - Map will store mapping of row -> {col -> val} 
    - This way the input matrix is stored in compressed form which will 
    get us better run time while multiplication.
    - Traverse map of first matrix row wise, now traverse map for every 
    col inside row, (row1, col1) of matrix1 is multipled with (col1, col) 
    i.e all the elements having row2 = col1 & product is added to 
    ans[row1, col2].

Follow up:
    - What if the input matrix are large and we can't save all of them in 
    memory?
        -> Compressed Matrix to map / vector
    - What if one matrix is sparse and other is dense?
        -> Store sparse matrix in map & traverse map and pick up corresponding
        idx from dense matrix & multiply
    - Instead of vectors being sparse, vector are represented as below 
    then calculate the dot product 
    [1,1,1,3,3,3,3,6,6]
    [0:3] 1
    [3:7] 3
    [7:9] 6 : Ref - 1868. Product of Two Run-Length Encoded Arrays
    - What if one vector is significantly longer than the other one?
        -> Traverse the shorter one & use binary search to find the 
        matched index in other matrix map, if we find some matched index 
        then we can use it as begin of next search, if we didn't find a 
        matched idx then return lower bound for next turn. Then runtime 
        will be O(M*logN) [m is len of short vector & n is len of longer 
        vector]
*/
class Solution {
public:
//TIME - O(N*M*K) SPACE - O(M*K + K*N)
    unordered_map<int, unordered_map<int, int>> compressMatrix(vector<vector<int>>matrix){
        //row -> {col -> val}
        unordered_map<int, unordered_map<int, int>>ans;
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] != 0) ans[i][j] = matrix[i][j];
            }
        }

        return ans;
    }
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int aM = mat1.size(), bM = mat2.size();
        int aN = mat1[0].size(), bN = mat2[0].size();

        vector<vector<int>>ans(aM, vector<int>(bN, 0));

        unordered_map<int, unordered_map<int, int>> compressed_Mat1 = compressMatrix(mat1);
        unordered_map<int, unordered_map<int, int>> compressed_Mat2 = compressMatrix(mat2);

        for(auto matrix1 : compressed_Mat1){
            int row_mat1 = matrix1.first;
            for(auto col1 : matrix1.second){
                int col_mat1 = col1.first;
                int element_mat1 = col1.second;
                
                int row_mat2 = col_mat1;
                for(auto col2 : compressed_Mat2[row_mat2]){
                    int col_mat2 = col2.first;
                    int element_mat2 = col2.second;

                    ans[row_mat1][col_mat2] += element_mat1 * element_mat2;
                }
            }
        }

        return ans;
    }
};