/*
Ques to ask :
    - What if both array don't have equal len
    - Can a element in array have 0 freq?

Sol :
=> Expanding both array : 
-> [TIME - O(N) SPACE - O(N)] N = sum of freq in array
    - Expand both array then multiply both array & store product in a 
    product array & use 2 pointer to compress it.
    - This will give TLE, as array can be big & time / space complexity 
    will become huge.

BEST APPROACH
=> Merge using 2 pointer : [TIME - O(min(len of array)) SPACE - O(1)]
    - Instead of expanding array, we take 2 pointer for each array
    - For each iteration, we add a product, and the minimum of two freq, 
    into our result array along with subtract this freq from both array, 
    move i/j pointer if the respecitve freq became 0
    - In end check if the product is equal to the last value in the result. 
    If so, increase the last frequency instead of adding a new value/freq 
    pair.

Follow up :
    - What if one vector could be sparse
        -> Ref : 1570. Dot Product of Two Sparse Vectors
        -> Ref : 311. Sparse Matrix Multiplication
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(min(len of array)) SPACE - O(1)
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int n = encoded1.size(), m = encoded2.size();
        vector<vector<int>>ans;
        //Pointer for encoded1 and encoded2
        int i = 0, j = 0;
        while(i < n && j < m){
            int val = encoded1[i][0] * encoded2[j][0];
            int freq = min(encoded1[i][1], encoded2[j][1]);

            //deduting freq, and moving to next pointer if freq is 
            //not 0
            encoded1[i][1] -= freq;
            encoded2[j][1] -= freq;
            //If freq is 0, means no val left to process, if it's left
            //then we can't move the pointer
            if(encoded1[i][1] == 0) i++;
            if(encoded2[j][1] == 0) j++;

            int ansSize = ans.size();
            //If current product val is same as last product value in 
            //product array then increment freq of last element else
            //add new element
            if(ansSize > 0 && ans[ansSize - 1][0] == val) 
                ans[ansSize - 1][1] += freq;
            else ans.push_back({val, freq});
        }

        return ans;
    }
};