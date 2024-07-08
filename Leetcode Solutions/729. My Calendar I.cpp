//TIME - O(N^2) SPACE - O(N)
class MyCalendar {
public:
    unordered_map<int,int>mp;
    MyCalendar() {
        mp = unordered_map<int,int>();
    }
    bool book(int start, int end) {
        for(auto it : mp){
            if(start<it.second && end>it.first) return false;
        }
        
        mp[start] = end; 
        return true;
    }
};

//TIME - O(NlogN) SPACE - O(N)
class MyCalendar {
public:
    set<int>start;
    set<int>end;
    MyCalendar(){
    }
    
    bool book(int _start, int _end) {
        auto interval_ended_before_start = upper_bound(end.begin(), end.end(), _start);
        auto interval_started_after_end = lower_bound(start.begin(), start.end(), _end);
        int t1 = distance(end.begin(), interval_ended_before_start);
        int t2 = distance(interval_started_after_end, start.end());
        int total_interval = start.size();
        
        if(total_interval - t1 - t2 > 0)
            return false;
        start.insert(_start);
        end.insert(_end);
        return true;
    }
};
//TIME - O(N + logN) SPACE - O(N)
//Using Binary Search find if there exist a element such that {start, end} fall in it,
//and if there doesn't exist then find the index where new {start, end} can be inserted.
class MyCalendar {
public:
    vector<pair<int, int>>v;
    MyCalendar() {
        v = vector<pair<int, int>>();
    }
    bool book(int start, int end) {
        int i = 0, j = v.size()-1;
        while(i <= j){
            int mid = i + (j-i)/2;
            if(v[mid].second > start && v[mid].first < end) return false;
            else if(v[mid].second <= start) i = mid + 1;
            else j = mid - 1;
        }

        v.insert(v.begin()+i, {start, end});
        return true;
    }
};