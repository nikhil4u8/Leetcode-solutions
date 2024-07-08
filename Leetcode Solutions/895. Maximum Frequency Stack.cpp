//TIME - O(1) O(N)
//SPACE - O(N)
class FreqStack {
public:
    unordered_map<int,int>index;
    vector<pair<int,pair<int,int>>>v;
    
    FreqStack() {
        v = vector<pair<int,pair<int,int>>>();
        index = unordered_map<int,int>();
    }
    void push(int val) {
        pair<int,pair<int,int>> temp;
        
        if(index.find(val) == index.end()) temp = {val,{1,-1}};
        else  temp = {val,{v[index[val]].second.first+1,index[val]}};
        
        v.push_back(temp);
        index[val] = v.size()-1;
    }
    
    int pop() {
        int maxi = -1;
        int val;
        for(int i=v.size()-1;i>=0;i--){
            if(maxi<v[i].second.first){
                maxi = v[i].second.first;
                val = v[i].first;
            }
        }

        v[index[val]].second.first = -2;
        if(v[index[val]].second.second != -1) index[val] = v[index[val]].second.second;
        else index.erase(val);
        
        return val;
    }
};

//TIME - O(1) O(!)
//SPACE - O(N)
class FreqStack {
public:
    unordered_map<int,stack<int>>mp;
    unordered_map<int,int>freq;
    int max_freq;
    
    FreqStack() {
        freq = unordered_map<int,int>();
        mp = unordered_map<int,stack<int>>();
        max_freq = 0;
    }
    void push(int val) {
        freq[val]++;
        max_freq = max(max_freq,freq[val]);
        mp[freq[val]].push(val);
    }
    
    int pop() {
        int res = mp[max_freq].top();
        mp[max_freq].pop();
        freq[res]--;
        
        if(mp[max_freq].empty()) max_freq--;
        return res;
    }
};
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */