/*
Ques to ask:
    - If target doesn't exist in array?

Sol :
=> Brute Force - [TIME - O(1) O(N)  SPACE - O(N)]
    - In Pick(), we'll simply store all indexes of numbers equal to target num in a vector & then generate a random_num from 0 to size_of_vec - 1, then return val of idx present at random_num_index in vector.
    - Drawback is that it requires extra space whenever Pick() is called.

BEST APPROACH
=> Cache using Hashmap - [TIME - O(N) O(1) SPACE - O(N)]
    - Instead of extracting all idx when Pick() is called, we'll precompute it using a hashmap which will store mapping of number -> vector of all indexes where this num is present.
    - Now, in Pick(), just find a random_index and return index value using map.
*/
class Solution {
public:
//TIME - O(N) O(1) SPACE - O(N)
    unordered_map<int, vector<int>>mp;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) mp[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        int vec_size = mp[target].size();
        int random_idx = rand() % vec_size;
        return mp[target][random_idx];
    }
};