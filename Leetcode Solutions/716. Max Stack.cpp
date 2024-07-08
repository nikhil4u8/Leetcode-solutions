//TIME - O(1) O(1) O(1) O(1) O(1) -> NOT SURE
//SPACE - O(N)
class MaxStack {
public:
    list<int>store;
    map<int, vector<list<int> :: iterator>>mp;
    MaxStack(){
    }
    
    void push(int x) {
        store.insert(store.begin(), x);
        mp[x].push_back(store.begin());
    }
    
    int pop() {
        auto it = store.begin();
        
        int ans = *it;
        
        mp[*it].pop_back();
        if(mp[*it].size() == 0) mp.erase(*it);
        
        store.erase(it);
        
        return ans;
    }
    
    int top() {
        return *store.begin();
    }
    
    int peekMax() {
        return mp.rbegin()->first;
    }
    
    int popMax() {
        int ans = mp.rbegin()->first;
        auto it = mp[ans][mp[ans].size()-1];
        
        mp[ans].pop_back();
        if(mp[ans].size() == 0) mp.erase(ans);
        
        store.erase(it);
        
        return ans;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */