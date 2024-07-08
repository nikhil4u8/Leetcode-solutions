class MyHashMap {
public:
    //Time - O(N/Bucket) O(N/Bucket) O(N/Bucket)
    vector<vector<pair<int,int>>>mapping;
    int bucket;
    
    MyHashMap() {
        bucket = 10000;
        mapping.resize(bucket);
    }
    void put(int key, int value) {
        int temp = key%bucket;
        
        for(int i=0;i<mapping[temp].size();i++){
            if(mapping[temp][i].first == key){
                mapping[temp][i].second = value;
                temp = -1;
                break;
            }
        }
        
        if(temp!=-1) mapping[temp].push_back({key,value});
        return;
    }
    int get(int key) {
        int temp = key%bucket;
        
        for(int i=0;i<mapping[temp].size();i++){
            if(mapping[temp][i].first == key) return mapping[temp][i].second;
        }
        
        return -1;
    }
    void remove(int key) {
        int temp = key % bucket;
        int index = -1;
        
        for(int i=0;i<mapping[temp].size();i++){
            if(mapping[temp][i].first == key){
                index = i;
                break;
            }
        }
        
        if(index != -1){
            int size = mapping[temp].size()-1;
            mapping[temp][index] = mapping[temp][size];
            mapping[temp].pop_back();
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */