/*
Similar Ques : 
    - Find min number of meeting room req?
        -> 253. Meeting Rooms II
    - Find if everyone can conduct a meeting in single meeting room?
        -> 252. Meeting Rooms 
*/
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] < intervals[i-1][1])
                return false;
        }
        
        return true;
    }
};