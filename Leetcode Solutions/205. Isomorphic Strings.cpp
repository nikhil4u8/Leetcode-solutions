class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, char>s_mp;
        unordered_map<char, char>t_mp;

        for(int i=0;i<s.length();i++){
            if(s_mp.find(s[i]) != s_mp.end() && s_mp[s[i]] != t[i]) return false;
            else if(s_mp.find(s[i]) == s_mp.end()){
                if(t_mp.find(t[i]) != t_mp.end() && t_mp[t[i]] != s[i]) return false;
                s_mp[s[i]] = t[i];
                t_mp[t[i]] = s[i];
            } 
        }

        return true;
    }
};