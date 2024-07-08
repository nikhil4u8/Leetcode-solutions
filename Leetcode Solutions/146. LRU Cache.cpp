/*
Desc :-
    - Get will return key if it exists, otherwise -1
    - Update value of key if it exist, otherwise add key-val pair, if 
    after adding capacity increase then remove least recently used.
    - Get / Put fun must run in O(1)

Ques to ask :-
    - What does the least recently used means?
    - What to return from get() func when key is not present?

Sol :
BEST APPROACH
=> Using list + map : [TIME - O(1) O(1) SPACE - O(N)]
    - Maintain a list data structure which will store key value pair as
    they come by in order & use a unordered_map to store mapping of key
    to the iterator at which this {key, val} pair is present in list
    - Get() -> check if key is present in map or not
        - If present, then return it's value & bring the {key, val} pair
        forward in list
        - If not present return -1
    - Put() -> check if key is already present or not
        - If present, then just replace the value & bring {key, val} pair
        forward in list
        - If not present then, add the new {key, val} pair at first position
        in list & if size of list becomes more than cap then remove 
        last element of list from map & list both & add
*/
//Using list + unordered map
//TIME - O(1) O(1)
class LRUCache {
public:
    list<pair<int, int>>order;
    unordered_map<int, list<pair<int, int>> :: iterator>key_index;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = key_index.find(key);
        if(it == key_index.end()) return -1;
        
        int val = it->second->second;

        order.erase(key_index[key]);
        order.push_front({key, val});
        key_index[key] = order.begin();

        return val;
    }
    
    void put(int key, int value) {
        auto it = key_index.find(key);

        if(it != key_index.end())
            key_index[key]->second = value;
        else if(order.size() == cap){
            auto it = order.end();
            it--;
            key_index.erase(it->first);
            order.erase(it);
        }

        if(it != key_index.end()) order.erase(key_index[key]);
        order.push_front({key, value});
        key_index[key] = order.begin();
    }
};
class LRUCache {
public:
// Using SET + UNORDERED_MAP -> Time - O(log[Cap])
//Set : {ranking, key}
//Map : {key, {ranking, value}}
    set<pair<int,int>>st;
    unordered_map<int,pair<int,int>>key_value;
    int cap;
    int rank = 0;
    
    LRUCache(int capacity) {
       cap = capacity;
    }
    
    int get(int key) {
        bool flag = key_value.find(key)==key_value.end();
        if(flag) return -1;

        int curr_rank = key_value[key].first;
        int val = key_value[key].second;
        
        rank++;
        auto it = st.find({curr_rank,key});
        st.erase(it);
        st.insert({rank,key});
        key_value[key] = {rank,val};
        
        return val;
    }
    
    void put(int key, int value) {
        bool flag = key_value.find(key) == key_value.end();
        
        if(st.size() == cap && flag){
            auto it = *st.begin();
            
            key_value.erase(it.second);
            st.erase(st.begin());
        }
        
        rank++;
        
        auto it = st.find({key_value[key].first,key});
        if(it!=st.end()) st.erase(it);
        
        key_value[key] = {rank,value};

        st.insert({rank,key});
    }
};