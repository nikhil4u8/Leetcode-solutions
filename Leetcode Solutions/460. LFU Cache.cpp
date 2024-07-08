class LFUCache {
public:
    LFUCache(int _capacity) {
        capacity=_capacity;
        size=0;
        min_freq=0;
    }
    
    int get(int key) {
        if(keysInfo.count(key)==0){
            return -1;
        }
        update(key);
        return keysInfo[key].first;
    }
    
    void put(int key, int value) {
        if(capacity<=0)
            return;
        
        if(keysInfo.count(key)==1){      //If key is already present 
            //update value
            keysInfo[key].first=value;
            update(key);
        }
        else{
            if(size==capacity){
                int key_to_remove=freq_to_key[min_freq].front();
                /*
                Remove from all three maps
                */
                freq_to_key[min_freq].pop_front();
                keysInfo.erase(key_to_remove);
                um_ref.erase(key_to_remove);
            }
            else
                size++;
            
            keysInfo[key]={value,1};
            min_freq=1;
            freq_to_key[1].push_back(key);
            um_ref[key]=(--freq_to_key[1].end());
        }   
    }
    
private :
    int capacity;
    int size;
    int min_freq;
    
    unordered_map<int,list<int> > freq_to_key;
    unordered_map<int,pair<int,int> > keysInfo;    //(key to {value,freq});
    unordered_map<int, list<int>::iterator> um_ref; //key to its iterator in freq_to_key list
    
    
    void update(int key){
        int curr_freq=keysInfo[key].second;
        auto it=um_ref[key];
        keysInfo[key].second++;
        freq_to_key[curr_freq].erase(it);
        curr_freq++;
        freq_to_key[curr_freq].push_back(key);
        um_ref[key]=(--freq_to_key[curr_freq].end());
        
        if(freq_to_key[min_freq].empty())
            min_freq++;
    }
};


class LFUCache {
public:
    int size;
    int minfreq;
    unordered_map<int,pair<int,int>>m;
    unordered_map<int,list<int>>mcount;
    unordered_map<int,list<int>::iterator>mlist;
    
    LFUCache(int capacity) {
        size = capacity;
        m.clear();
        mlist.clear();
        mcount.clear();
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        
        int c = m[key].second;
        mcount[c].erase(mlist[key]);
        if(mcount[c].empty()){
            if(minfreq==c)minfreq++;
        }
        mcount[c+1].push_front(key);
        mlist[key] = mcount[c+1].begin();
        m[key].second++;
        
        return m[key].first;
    }
    
    void put(int key, int value) {
        if(m.size()==size && m.count(key)==0){
            // evict
            if(size==0)return;
            int k = mcount[minfreq].back();
            m.erase(k);
            mlist.erase(k);
            mcount[minfreq].pop_back();
        }
        if(m.count(key)==0){
            m[key] = {value,1};
            minfreq = 1;
            mcount[1].push_front(key);
            mlist[key] = mcount[1].begin();
        }
        else{
            int c = m[key].second;
            mcount[c].erase(mlist[key]);
            if(mcount[c].empty()){
                if(minfreq==c)minfreq++;
            }
            mcount[c+1].push_front(key);
            mlist[key] = mcount[c+1].begin();
            m[key].first = value;
            m[key].second++;
        }
    }    
};