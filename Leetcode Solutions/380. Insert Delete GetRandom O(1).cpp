/*
Ques to ask :
    - Can GetRandom be called when there are no elements?
    - Are duplicate allowed?
    
Sol :-
    - Take a hashmap, and simply perform insert / remove / getRandom 
    on it in O(1) O(1) O(N) time complexity.
    - Take a hashmap (val -> index in array) and array (idx -> val), 
    in remove fun just swap the removing element with the last element, 
    to perform remove in O(1) time.

Edge case :-
    - For second approach -> when item removed is the last item in 
    array / only item in array.

Follow up :- Given below
*/

class RandomizedSet {
public:
    //TIME - O(1) O(1) O(N) SPACE - O(N)
    unordered_map<int,int>mp;
    RandomizedSet() {
    }
    
    bool insert(int val){
        mp[val]++;
        return mp[val]==1;
    }
    
    bool remove(int val) {
        bool flag = mp[val]>0;
        mp.erase(val);
        return flag;
    }
    
    int getRandom() {
        int random_num = rand()%(mp.size());
        //next is same implementation as 
        //auto it = mp.begin();
        //for(int i=0;i<random_num;i++,it++)
        return next(mp.begin(),random_num)->first; 
    }
};

**FOLLOW-UP 
    1.Implement all the func in O(1) time complexity
    2.In case of duplicates numbers are given and probability should be acc. to freq.
        -use a multiset
        -use a unordered_map and vector 
//Follow - up :- 1
//TIME - O(1) O(1) O(1)
class RandomizedSet {
public:
    //{val -> idx of array}
    unordered_map<int, int>mp; 
    //idx -> val
    vector<int>idx;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        
        mp[val] = idx.size();
        idx.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int end_ptr = idx.size()-1;

        //swapping val_idx with the last element in idx array
        int val_idx = mp[val];
        mp[idx[end_ptr]] = val_idx;
        idx[val_idx] = idx[end_ptr];

        //removing val element
        mp.erase(val);
        idx.pop_back();

        return true;
    }
    
    int getRandom() {
        int random_index = rand() % (idx.size());
        return idx[random_index];
    }
};

//Follow - up :- 2
//METHOD - 1
class RandomizedCollection {
public:
    // val -> vector of position of val in v array
    unordered_map<int,vector<int>>mp;
    // {val,position/index of this element in map[val] array}
    vector<pair<int,int>>v;
    RandomizedCollection() {
        mp = unordered_map<int,vector<int>>();
        v = vector<pair<int,int>>();
    }
    
    bool insert(int val) {
        bool flag = mp[val].size() == 0;
        
        mp[val].push_back(v.size());
        v.push_back({val,mp[val].size()-1});
        
        return flag;
    }
    
    bool remove(int val) {
        bool flag = mp[val].size() > 0;
        if(!flag) return false;
        
        auto last = v[v.size()-1];
        mp[last.first][last.second] = mp[val][mp[val].size()-1];
        v[mp[val].back()] = last;
        mp[val].pop_back();
        
        if(mp[val].empty()) mp.erase(val);
        v.pop_back();
        
        return true;
    }
    
    int getRandom(){
        return v[rand()%(v.size())].first;
    }
};

//METHOD - 2
class RandomizedCollection {
public:
    multiset<int>mp;
    RandomizedCollection() {
        mp.clear();
    }
    
    bool insert(int val) {
        bool out=true;
        if(mp.find(val)!=mp.end()) out=false;
        mp.insert(val);
        return out;
    }

    bool remove(int val) {
        auto d=mp.find(val);
        if(d==mp.end()) return false;
        mp.erase(d);
        return true;
    }
    
    int getRandom() {
        auto it=mp.begin();
        int ran=rand()%mp.size();
        //can be used instead of for loop
        //return *next(it,ran);
        for(int i=0;i<ran;i++,it++);
        return *it;
    }
};
