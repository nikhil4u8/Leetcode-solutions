class SnapshotArray {
public:
    vector<unordered_map<int,int>>snapshot;
    int id;
    SnapshotArray(int length) {
        id = 0;
        snapshot = vector<unordered_map<int,int>>(length);
    }
    
    void set(int index, int val) {
        snapshot[index][id] = val;
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        if(snap_id > id-1) return 0;
        for(int i=snap_id;i>=0;i--){
            if(snapshot[index].find(i) != snapshot[index].end()) return snapshot[index][i];
        }    
        return 0;
    }
};