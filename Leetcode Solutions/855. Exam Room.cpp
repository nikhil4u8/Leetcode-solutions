//TIME - O(T) O(logT) SPACE - O(N)
//T is no of seats occupied
//N is total seats
class ExamRoom {
public:
    set<int>st;
    int cap;
    ExamRoom(int n) {
        cap = n;
    }
    
    int seat() {
        if(st.size() == 0){
            st.insert(0);
            return 0;
        }
        
        int first = *st.begin(), second = -1, pos = -1, gap = 0;
        for(auto it : st){
            if(it == *st.begin()){
                first = it;
                gap = first - 0;
                pos = 0;
                continue;
            }
            
            second = it;
            int temp_pos = (first + second)/2;
            int temp_gap = min(temp_pos - first, second - temp_pos);
            
            if(temp_gap > gap){
                gap = temp_gap;
                pos = temp_pos;
            }
            
            first = second;
        }
        
        if(second != cap - 1 && cap-1-first > gap){
            gap = cap - 1 - first;
            pos = cap - 1;
        }
        
        st.insert(pos);
        
        return pos;
    }
    //TIME - O()
    void leave(int p) {
        auto it = st.find(p);
        st.erase(it);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */