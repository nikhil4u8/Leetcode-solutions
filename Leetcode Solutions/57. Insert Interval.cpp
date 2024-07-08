class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        
        int i = 0;
        // add all the intervals ending before newInterval starts
        while(i < intervals.size() && newInterval[0] > intervals[i][1]) 
            ans.push_back(intervals[i++]);
        // merge all overlapping intervals to one considering newInterval
        while(i<intervals.size() && newInterval[1] >= intervals[i][0]){
            newInterval = {
                min(newInterval[0],intervals[i][0]),
                max(newInterval[1],intervals[i][1])
            };
            i++;
        }
            
        ans.push_back(newInterval);//add the union of intervals we got
        // add all the rest
        
        while(i<intervals.size())
            ans.push_back(intervals[i++]);
        
        return ans;
    }
};