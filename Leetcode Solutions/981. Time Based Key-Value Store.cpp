/*
TIME - O(L⋅M⋅logM) O(N⋅(L⋅logM+logM))
SPACE - O(M⋅L) O(1)
where L is the length of the value and M is the number of calls
*/
class TimeMap {
public:
    unordered_map<string, map<int, string>>mp;
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";

        //return iterator pointing to the immediate next element just greater than timestamp
        auto it = mp[key].upper_bound(timestamp);
        if(it == mp[key].begin()) return "";

        return prev(it)->second;
    }
};

class TimeMap {
public:
    unordered_map<int,pair<string,string>>mp;
    TimeMap() {
        mp = unordered_map<int,pair<string,string>>();
    }
    void set(string key, string value, int timestamp) {
        mp[timestamp] = {key,value};   
    }
    string get(string key, int timestamp) {
        for(int i=timestamp;i>=1;i--){
            if(mp.find(i) != mp.end() && mp[i].first == key) return mp[i].second;
        }
        return "";
    }
    //to improve time complexity we can use Binary Search in GET method instead of for loop
};
