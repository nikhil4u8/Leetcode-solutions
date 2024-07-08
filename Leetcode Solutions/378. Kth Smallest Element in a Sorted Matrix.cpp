/*
Ques to ask : 
    - Can k == 0 or K > n^2?
    - What if k = 1 & input = [1,1], then what do we return?

Sol : 
=> Sorting : [TIME - O(NMlog(NM)) SPACE - O(1)]
    - Simpy put all element of matrix in a array & sort it & return 
    starting k elements

=> Using Max Heap : [TIME - O(N*M*logK) SPACE - O(K)]
    - Put all element in max heap, and once the size of heap reaches K 
    then pop out element & return element which are left in heap

BEST APPROACH
=> Binary search : [TIME - O(N*log(maxi-mini)) Space - O(1)]
    - We'll do a binary search b/w mini (matrix[0][0]) to maxi 
    (matrix[n-1][m-1]) element in matrix and for each mid count elements 
    less than mid, if count == K-1, then return mid it else ignore

Follow up :
    - Solve it in constant memory (i.e., O(1) memory complexity)?
    - Solve it in O(n) time complexity? 
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();

        int start = matrix[0][0], end = matrix[n-1][m-1];
    
        while(start < end){
            int mid = start + (end - start)/2;
            int count = 0, j = n-1;
            //counting how many element have val < mid
            for(int i=0;i<n;i++){
                while(j>=0 && matrix[i][j]>mid) j--;
                count += j+1;
            }
            //if elements whose val < mid is <k, then we need to move 
            //our search space to right else to left
            if(count < k) start = mid + 1;
            else end = mid;
        }

        return start;
    }
};