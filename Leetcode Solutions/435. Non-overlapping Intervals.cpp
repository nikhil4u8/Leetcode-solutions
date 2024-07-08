/*
Ques to ask : 
    - Is interval array sorted?
    - Can interval array contains duplicate interval?

Sol : 
BEST APPROACH
=> Simple removal of interval : [TIME - O(NlogN) SPACE - O(1)]
    - Sort the array and traverse the sorted array.
    - We've 3 cases : 
        - [1, 3], [4, 5] : don't need to remove any interval
        - [1, 7], [4, 5] : remove element with largest end point
        - [1, 6], [3, 7] : remove element with largest end point
*/
class Solution {
public:
//BEST APPROACH
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int ans = 0, start = intervals[0][0], end = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0] < end){
                ans++;
                if(intervals[i][1] > end) continue; 
            }
            start = intervals[i][0];
            end = intervals[i][1];
        }

        return ans;
    }
};