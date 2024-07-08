//11:05
/*
Brute force
calculating all free intervals of all employee and start merging them one by one

TIME - O(N*K)
SPACE - O(N)

N is total number of intervals in list
K is total employee in list
*/
// class Solution {
// public:
//     vector<Interval> CommonInterval(vector<Interval>&temp1, vector<Interval>&temp2){
//         if(temp1.size() == 0 || temp2.size() == 0) return {};
        
//         vector<Interval>ans;
        
//         int i=0,j=0;
//         while(i<temp1.size() && j<temp2.size()){
//             int start = max(temp1[i].start, temp2[j].start);
//             int end = min(temp1[i].end, temp2[j].end);
//             if(start >= end){
//                 if(start == temp1[i].start) j++;
//                 else i++;
//                 continue;
//             }
            
//             if(temp1[i].start == temp2[j].start && temp1[i].end == temp2[j].end){
//                 i++;j++;
//             }else if(temp1[i].end > temp2[j].end) j++;
//             else i++;
            
//             Interval new_interval(start, end);
//             ans.push_back(new_interval);
//         }
        
//         return ans;
//     }
//     vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
//         vector<Interval>ans;
        
//         for(int i=0;i<schedule.size();i++){
//             vector<Interval>temp;
//             for(int j=0;j<schedule[i].size();j++){
//                 if(j == 0){
//                     temp.push_back({INT_MIN, schedule[i][j].start});
//                     temp.push_back({schedule[i][j].end, INT_MAX});
//                 }else{
//                     int len = temp.size();
//                     temp[len-1].end = schedule[i][j].start;
//                     temp.push_back({schedule[i][j].end, INT_MAX});
//                 }
//             }
//             if(ans.size() == 0) ans = temp;
//             else ans = CommonInterval(ans, temp);
//         }
        
//         if(ans.size() != 0) ans.pop_back();
//         if(ans.size() != 0) ans.erase(ans.begin());
        
//         return ans;
//     }
// };

/*
Using count maximum room required for meeting technique
we have marked entry point as '+' and exit point as '-', and traverse through map and if we found "'-' '+'" pattern and there are no current meeting going on then that means this intervals is free i.e before starting new interval (symbolize by '+') all other meetings got ended (symbolize by.'-')
TIME - O(NlogN)
SPACE - O(N)
N is total number of intervals in list
*/
// class Solution {
// public:
//     vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule){
//         map<int,int>timestamp;
//         for(int i=0;i<schedule.size();i++){
//             for(int j=0;j<schedule[i].size();j++){
//                 timestamp[schedule[i][j].start]++;
//                 timestamp[schedule[i][j].end]--;
//             }
//         }
        
//         vector<Interval>ans;
//         int curr_status = 0, last_time = 0;
//         for(auto it : timestamp){
//             curr_status += it.second;
//             if(curr_status == 0) ans.push_back({it.first, INT_MAX});
//             if(curr_status != 0 && !ans.empty() && ans.back().end == INT_MAX) ans.back().end = it.first;
//         }
        
//         if(ans.back().end == INT_MAX) ans.pop_back();
        
//         return ans;
//     }
// };
/*
Using concepts from "Merge K sorted list" and "Merge intervals"
TIME - O(NlogK)
SPACE - O(K)

N is total intervals in schedule
K is total employee
*/
#define ppi pair<int,pair<int,int>>
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        //{start_time, {employee_index, interval_index}}
        vector<Interval> ans;
        if (schedule.empty()) return ans;
        
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        
        for(int i=0; i<schedule.size(); ++i)
                pq.push({schedule[i][0].start, {i, 0}});
        
        int end_time = schedule[pq.top().second.first][0].end;
        
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            
            int start_time = p.first;
            int intervalIndex = p.second.second;
            int employeeIndex = p.second.first;
            int curr_end_time = schedule[employeeIndex][intervalIndex].end;
            
            if (start_time > end_time) {
                ans.push_back(Interval{end_time, start_time});
                end_time = curr_end_time;
            }else
                end_time = max(end_time, schedule[employeeIndex][intervalIndex].end);
            
            ++intervalIndex;
            if (intervalIndex < schedule[employeeIndex].size()) {
            
                pq.push({schedule[employeeIndex][intervalIndex].start,
                         {employeeIndex, intervalIndex}});
            }
            
        }
        return ans;
    }
};