class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.length()) return false;
        
        unordered_map<char, int>mp;
        for(int i=0;i<s.length();i++) mp[s[i]]++;
        
        int count = 0;
        for(auto it : mp){
            if(it.second % 2 != 0) count++;
        }
        
        return count <= k;
    }
};