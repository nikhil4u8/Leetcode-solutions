//METHOD - 1
class RandomizedCollection {
public:
    unordered_map<int,vector<int>>mp;
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
        for(int i=0;i<ran;i++,it++);
        return *it;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */