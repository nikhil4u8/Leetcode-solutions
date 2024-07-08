class FirstUnique {
public:
    //Approach -1
    //TLE
    unordered_map<int,pair<int,int>>mp;
    int count;
    FirstUnique(vector<int>& nums) {
        count = 0;
        for(int i=0;i<nums.size();i++) add(nums[i]);
    }
    int showFirstUnique() {
        int val = -1,mini=INT_MAX;
        for(auto it : mp){
            if(it.second.first == 1 && mini > it.second.second){
                mini = it.second.second;
                val = it.first;
            }
        }
        return val;
    }
    void add(int value) {
        count++;
        if(mp.find(value) == mp.end()) mp[value] = {0,count}; 
        mp[value].first++;
    }
    
    //Approach - 2
    //Not TLE
    unordered_map<int,int>mp;
    vector<int>v;
    FirstUnique(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) add(nums[i]);
    }
    int showFirstUnique() {
        for(int i=0;i<v.size();i++){
            if(mp[v[i]] == 1) return v[i];
        }
        return -1;
    }
    void add(int value) {
        if(mp.find(value) == mp.end()) v.push_back(value);
        mp[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */