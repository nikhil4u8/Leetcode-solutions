/*
Ques to ask :
    - Can we've a row having 0 elements?

Sol :
BEST APPROACH
=> Group by row + col : [TIME - O(N*M) SPACE - O(N*M)]
    - In 2D matrix, all elements sharing the same diagonal have same sum 
    of their indexes i.e (row + col). So we'll traverse the matrix & use 
    a map to store the mapping from {row + col} as a key to all the 
    diagonal elements. For each bucket starting from 0 to maxIdx, print 
    all the elements.
    - Here, diagonals are from bottom to top, but we traversed matrix from 
    first row to last row, hence we need to add element to final vector in 
    reverse order.

Similar Ques : 
    - Traverse diagonally if each row has different number of element?
        -> 1424. Diagonal Traverse II
    - If each row has same num of elements?
        -> 498. Diagonal Traverse
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(N*M) SPACE - O(N*M)
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int>ans;
        unordered_map<int, vector<int>>mp;
        int maxIdx = 0;

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                mp[i+j].push_back(nums[i][j]);
                maxIdx = max(maxIdx, i+j);
            }
        }

        //adding elements from map to ans vector in reverse order
        for(int i=0;i<=maxIdx;i++)
            ans.insert(ans.end(), mp[i].rbegin(), mp[i].rend());

        return ans;
    }
};