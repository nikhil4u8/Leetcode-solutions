/*
Ques to ask :
    - What to return when whole matrix is 0?
    - Empty matrix ?
    - Is there any limit to no of get call made?

Sol :
BRUTE FORCE - 1
=> Column wise traversal [TIME - O(N*M) SPACE - O(1)]
    - Traverse in each col starting from 0 & check if it contains '1', ]
    if it does then return col idx, otherwise move on to next col.
    - Too many get calls, and more time complexity

BRUTE FORCE - 2
=> Row wise Linear traversal [TIME - O(N*M) SPACE - O(1)]
    - Traverse each row linearly, until we find '1', if found at idx j 
    then reduce search space for next row i.e (0,j)

BRUTE FORCE - 3
=> Row wise Binary search traversal [TIME - O(NlogM) SPACE - O(1)]
    - Since row are sorted so we use Binary search instead of linear
    - Apply BS in first row & find min index (j) at which '1' is present.
    - Reduce search space for the next row i.e (0,j)
    - Meanwhile keep track of min col index at which '1' is found


BEST APPROACH
=> Row wise traversal - Start at Top Right, Move Only Left and Down
    - TIME : O(N+M) SPACE - O(1)
    - Traverse first row in reverse & find idx (j) of first col whose val is 1
    - Reduce the search space for next row i.e (0, j) & traverse it
    - Repeat above steps until all row are traversed.
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(N+M) SPACE - O(1)
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int>dimension = binaryMatrix.dimensions();
        int row = dimension[0];
        int col = dimension[1];
        
        int curr_row = 0, curr_col = col-1;
        
        while(curr_row < row && curr_col >= 0){
            if(binaryMatrix.get(curr_row, curr_col) == 1) curr_col--;
            else curr_row++;
        }
        
        return curr_col == col - 1 ? -1 : curr_col + 1;
    }

//BINARY SEARCH TRAVERSAL IN EACH ROW
//TIME - O(NlogM) SPACE - O(1)
    int search(int row, int col, BinaryMatrix &binaryMatrix){
        int i = 0, j = col, ans = col;

        while(i<j){
            int mid = i + (j-i)/2;
            
            if(binaryMatrix.get(row, mid) == 1){
                ans = min(mid, ans);
                j = mid;
            }else i = mid + 1;
        }
        
        return ans;
    }
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int>dimension = binaryMatrix.dimensions();
        int row = dimension[0];
        int col = dimension[1];
        
        int last = col;
        
        for(int i=0;i<row;i++){
            if(last == col && binaryMatrix.get(i, last-1) == 1) 
                last = min(last, search(i, last, binaryMatrix));
            else if(last != col && binaryMatrix.get(i, last) == 1)
                last = min(last, search(i, last, binaryMatrix));
        }
        
        return last == col ? -1 : last;
    }
};