/*
Similar Ques : 
    - Traverse diagonally if each row has different number of element?
        -> 1424. Diagonal Traverse II
    - If each row has same num of elements?
        -> 498. Diagonal Traverse
*/
class Solution {
public:
//TIME - O(N*M) SPACE - O(1)
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;    
        int n = mat.size();
        if(n == 0) return ans;
        int m = mat[0].size();
        int totalDiag = n + m - 1, i = 0, j = 0;
        bool directionUp = true;

        //running loop until we've traversed all diagonals
        while(totalDiag--){
            //condition when diag going upwards
            if(directionUp){
                if(i == n){
                    j += 2;
                    i--;
                }else if(j == -1) j++;

                while(i >= 0 && j < m){
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
            }else{ //condition when diagonal is going down
                if(j == m){
                    i += 2;
                    j--;
                }else if(i == -1) i++;

                while(i < n && j >= 0){
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
            }
            //reversing direction
            directionUp = !directionUp;
        }

        return ans;
    }
};