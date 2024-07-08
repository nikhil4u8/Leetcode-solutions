/*
Ques to ask :-
    - Is the array given sorted?

Sol :
=> SAY THIS IN START
    - Multiple meeting rooms are required when we've multiple overlapping 
    meetings.
    - To find min meeting rooms require, we need to find max number of 
    overlapping meetings

BEST APPROACH
=> Using Priority Queue - [TIME - O(NlogN) SPACE - O(N)]
    - Sorting the array based on start time, maintaining a min heap & put 
    {ending_time} of meeting in heap one by one
    - When a new meeting comes then we'll remove all previous meetings 
    from heap which already ended before starting the current meeting
    - Meanwhile keep track of max size of min pq and return that. 

=> Number Line logic - [TIME - O(NlogN) SPACE - O(N)]
    - Considering meeting on a number line, and marking starting of meeting 
    as +1 and ending as -1, so now if we traverse that number line and 
    maintain a variable roomRequired, so add +1 when a meeting starts, 
    and -1 when meeting ends, then we need to find max(roomRequired) to 
    find min meetings room required to conduct all meetings.

Edge cases :-
    - Intervals is empty
    - Multiple meetings at same time

Similar Ques : 
    - Find min number of meeting room req?
        -> 253. Meeting Rooms II
    - Find if everyone can conduct a meeting in single meeting room?
        -> 252. Meeting Rooms 

Follow ups :- See below
*/

class Solution {
public:
//APPROACH 1 : HEAP
    //TIME - O(NlogN) space - O(N)
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int max_room = 0;
        //Sort by meeting start time.
        sort(intervals.begin(),intervals.end());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(intervals[0][1]);
        
        for(int i=1;i<intervals.size();i++){
            int start_time = intervals[i][0];
            int end_time = intervals[i][1];
            //Removing all meeting which have already ended before curr_meeting start
            while(!pq.empty() && start_time>=pq.top()) pq.pop();
            pq.push(intervals[i][1]);

            max_room = max(max_room,pq.size());
        }
        return max_room;
    }
//APPROACH 2 : Number Line
    //TIME - O(NlogN)  SPACE - O(N)
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        vector<pair<int,int>>v;
        for(int i=0;i<intervals.size();i++){
            v.push_back({intervals[i][0],1});
            v.push_back({intervals[i][1],-1});
        }
        
        sort(v.begin(),v.end());
        
        int res = 0,maxi=0;
        for(int i=0;i<v.size();i++){
            res += v[i].second;
            maxi = max(maxi,res);
        }
        
        return maxi;
    }
};

**FOLLOW-UP
    1.Range of time - {startTime, endTime} when the maximum number of 
    rooms were in use / Find the peak time.
    2.Output the meeing schedule for each room
    3.Number of Requried room at a certain point

1.
/*
Sol : After removing all meeting which ended before starting curr meeting,
check if heap size is maximum or not, if it's max then curr time interval
has most meetings
*/
vector<pair<int,int>> minMeetingRooms(vector<vector<int>>& intervals) {
        int max_room = 0;
        vector<pair<int,int>>range_of_time;
        //Sort by meeting start time.
        sort(intervals.begin(),intervals.end());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(intervals[0][1]);
        
        for(int i=1;i<intervals.size();i++){
            int start_time = intervals[i][0];
            int end_time = intervals[i][1];
            //Removing all meeting which have already ended before curr_meeting start
            while(!pq.empty() && start_time>=pq.top()) pq.pop();
            pq.push(intervals[i][1]);

            if(max_room <= pq.size()){
                if(max_room<pq.size()) range_of_time.clear();
                range_of_time.push_back({start_time,end_time});                
            }

            max_room = max(max_room,pq.size());
        }
    return range_of_time;
}
2.
/*
Sol : Here heap will store {end_time, room_id}, whenever a meeting finishes
then we'll put new meeting into that room, if no meeting finishes then we've
to create new room to accomodate new meetings. And we'll keep track which
meeting are held in which room using a array & return that array
*/
vector<vector<vector<int>>> minMeetingRoomSchedule(vector<vector<int>>& intervals) {
    vector<vector<vector<int>>>ans;
	// sort the interval based on the start time, the end time doesn't matter
    sort(intervals.begin(), intervals.end()); 

    //<latest meeting end time, room id>
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    
    for(int i=0;i<intervals.size();i++) {
        int start_time = intervals[i][0];
        int end_time = intervals[i][1];
        int room_id = 0;
        // the room with the earliest end time has finished before curr_meeting
        if (!pq.empty() && pq.top()[0]<=start_time) {
            room_id = pq.top()[1];
            pq_room.pop();
        }// need a new room
        else{
            room_id = pq_room.size();
            //expanding ans
            if(room_id>ans.size()) ans.push_back({});  
        }
        pq.push({end_time, room_id});
        ans[room_id].push_back({start_time,end_time});
    }
    return ans;
}
3. Just return the size of prioirty_queue at the required point
