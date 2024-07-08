class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,vector<int>>mp;
        
        for(int i=0;i<s.length();i++) mp[s[i]].push_back(i);
        
        int mini = INT_MAX;
        
        for(auto it:mp){
            if(it.second.size()==1) mini = min(mini, it.second[0]);
        }
        
        if(mini == INT_MAX) return -1;
        return mini;
    }
};