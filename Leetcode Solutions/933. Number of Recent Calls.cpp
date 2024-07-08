class RecentCounter {
public:
    //Time - O(N^2)
    vector<int>v;
    RecentCounter() {
        v = vector<int>();
    }
    //Time - O(N)
    int ping(int t) {
        v.push_back(t);
        int count = 0;
        
        for(int i=v.size()-1;i>=0;i--){
            if(v[i] >= t - 3000) count++;
            else break;
        }
        
        return count;
    }
    //Using Sliding Window
    //Time - O(N)
    int start_index,end_index;
    vector<int>v;
    RecentCounter() {
        v = vector<int>();
        start_index = -1;
        end_index = -1;
    }
    //Time - O(N)
    int ping(int t) {
        v.push_back(t);
        end_index++;
        if(start_index == -1) start_index++;
        while(v[end_index] - v[start_index] > 3000) start_index ++;
        
        return end_index - start_index + 1;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */